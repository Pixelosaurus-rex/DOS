#include <conio.h>
#include <stdio.h>

int main()
{
  clrscr();

  if(kbhit())
  {
    printf("hit\n");
  }

  return 0;
}