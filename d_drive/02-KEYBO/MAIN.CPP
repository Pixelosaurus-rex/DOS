#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
  char kc = 0;
  char s[255];

  clrscr();

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

  return 0;
}