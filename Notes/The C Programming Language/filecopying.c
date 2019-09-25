#include <stdio.h>
/* Read a character
while (character ios not end-of-file indicator) 
    ouput the character just read
    read a character
*/
/* copy input to output; 1st version*/
main()
{
    int c;
    c = getchar();
    while (c != EOF) {
        putchar(c);
        c = getchar();
    }
}