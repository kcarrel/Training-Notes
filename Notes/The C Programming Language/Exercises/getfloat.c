#include <stdio.h>
#include <ctype.h>

#define SIZE 1000
int getch(void);
void ungetch(int);
int getfloat(float *);

int main(void)
{
    int n;
    float array[SIZE];

    for(n = 0;n < SIZE && getfloat(&array[n]) != EOF; n++){
       ;
    for (; n >= 0; n--)
        printf("%f", array[n]);
    return 0;
}

int getfloat(float *pointer)
{
    int c,sign;
    float power;
    //skip whitespaces
    while(isspace(c=getch()))
        ;
    // check to see if its a num 
    if( !isdigit(c) && c!=EOF && c!= '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }
    
    sign = ( c == '-') ? -1: 1;

    if( c == '+' || c == '-')
        c = getch();

    for(*pointer = 0.0 ; isdigit(c);c=getch())
        *pointer = 10.0 * *pointer + (c - '0');
    if( c == '.')
        c = getch();

    for(power=1.0;isdigit(c);c=getch())
    {
        *pointer = 10.0 * *pointer + (c - '0');   /* fractional part */
        power *= 10.0;
    }

    *pointer  *= sign / power;

    if( c != EOF)
        ungetch(c);
    
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0)? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++]=c;
}