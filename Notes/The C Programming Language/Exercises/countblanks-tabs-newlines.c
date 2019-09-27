#include <stdio.h>

main()
{
    int c, nl, b, t;
    nl, b, t = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
        else if ( c == '\t')
            ++t;
        else if ( c == ' ')
            ++b;
    printf("%d\n", nl);
    printf("%d\t", t);
    printf("%d\b", b);

}