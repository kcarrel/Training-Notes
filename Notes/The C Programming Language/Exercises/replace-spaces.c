#include <stdio.h>
#define TABINC 8

int main(void)
{
    int blanks,tabs,chars,c;
    
    blanks = 0;
    tabs = 0;
    
    for(chars=1;(c=getchar())!=EOF;++chars)
        if( c == ' ')
        {
            if((chars % TABINC) != 0)
                ++blanks;
            else
            {
                blanks = 0;
                ++tabs;
            }
        }
        else 
        {
            for( ; tabs > 0 ; --tabs)
                putchar('\t');
            if( c == '\t')
                blanks = 0;
            else
                for( ; blanks > 0; --blanks)
                    putchar(' ');
            
            putchar(c);
            
            if(c == '\n')
                chars = 0;
            else if ( c == '\t')
                chars = chars + ( TABINC - (chars -1) % TABINC) - 1;
        }

    return 0;
}