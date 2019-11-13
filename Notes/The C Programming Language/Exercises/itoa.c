/* previous version of itoa used the range of an 8 bit variable */


/* updated to take in a min field width argument*/
#include <stdio.h>
#include <string.h>
#define MAX 100

void itoa(int n,char s[], int w);
void reverse(char s[]);


int main(void)
{
    int number, min;
    char string[MAX];
    
    number = -223451;
    min = 5;

    itoa(number,string, min);
    printf("Printing integer %d as a string: %s", number, string);

    return 0;
}

void itoa(int n,char string[], int min)
{
    int i,sign;
    sign=n; 
    if (sign < 0)
        n = -n;
    i = 0;
     
    do
    {
        string[i++] = (n % 10) + '0';
    } while ((n /= 10) > 0);
    if(sign <0)
        string[i++]='-';

    while(i < min)
        string[i++]=' ';
    string[i]='\0';
    
    reverse(string);
}

void reverse(char string[])
{
    int c,i,j;

    for(i=0,j=strlen(string)-1;i<j;i++,j--)
        c=string[i],string[i]=string[j],string[j]=c;
}
    