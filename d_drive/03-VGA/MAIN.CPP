#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dos.h>

// Bit "haut" pour l'int‚ruption du mode vid‚o
#define SET_MODE 0x00
// Interupt pour le mode vid‚o
#define VIDEO_INT 0x10
// Modes vid‚os utilis‚s
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03
#define SCREEN_HEIGHT 200
#define SCREEN_WIDTH 320

typedef unsigned char byte;

// 0xA000:0000L (L car c'est une adresse "longue"
byte far *VGA=(byte far *)0xA0000000L;

// Macro pour d‚finir un pixel
// R‚cupŠre le pointeur de l'adresse m‚moire correpondante
// et y met la valeur de "c".
#define SETPIX(x, y, c) *(VGA+(x)+(y)*SCREEN_WIDTH)=c
// Macro pour r‚cup‚rer la valeur d'un pixel
#define GETPIX(x, y) *(VGA+(x)+(y)*SCREEN_WIDTH)

/*
 * Change le mode vid‚o du systŠme
 */
void set_mode(byte mode)
{
  union REGS regs;
  regs.h.ah = SET_MODE;
  regs.h.al = mode;
  int86(VIDEO_INT, &regs, &regs);
}

void draw_background()
{
  int x, y;

  for(y= 0; y < SCREEN_HEIGHT; ++y)
  {
    for(x = 0; x < SCREEN_WIDTH; ++x)
    {
      SETPIX(x, y , y);
    }
  }
}

int main()
{
  printf("Test");

  set_mode(VGA_256_COLOR_MODE);

  char kc = 0;
  char s[255];

  clrscr();
  draw_background();

  while(kc != 0x1b) // ESC
  {
    if(kbhit())
    {
      kc = getch();
      if(kc == (char) 0) {
	kc = getch();
	switch(kc)
	{
	  case 0x48: // UP
	    strcpy(s, "up arrow");
	    break;
	  case 0x50: // DOWN
	    strcpy(s, "down arrow");
	    break;
	  default:
	    sprintf(s, "00 %02x", kc);
	    break;
	}
      } else {
	sprintf(s, "%02x", kc);
      }
      printf("Key pressed: %s\n", s);
    }
  }

  set_mode(TEXT_MODE);

  return 0;
}