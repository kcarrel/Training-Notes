#include <stdio.h>
#define TABINC 8

int main(void)
{
  int blanks,characters,c;
  blanks = 0;
  characters = 1;

  while((c=getchar())!=EOF)
  {
    if( c == '\t')
    {
      blanks = TABINC - (( characters - 1) % TABINC);

      while( blanks > 0)
      {
        putchar('-');
        ++characters;
        --blanks;
      }
    }
    else if( c == '\n')
    {
      putchar(c);
      characters = 1;
    }
    else
    {
      putchar(c);
      ++characters;
    }
  }

  return 0;
}