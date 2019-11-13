#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

/* Make the itoa exercise recursive!*/
void itoa(int n,char s[]);
int main(void)
{
    int number;
    char string[MAX];
    
    number = -223451;

    itoa(number,string);
    printf("%s", string);

    return 0;
}

void itoa(int n,char string[])
{
    static int i;
    if (n/10)
        itoa(n/10, string);
    else 
    {
        i = 0;
        if (n < 0)
            string[i++] = '-';
    }
    string[i++] = abs(n) % 10 + '0';
    string[i]='\0';
}
