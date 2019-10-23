#include <stdio.h>
#include <string.h>
#define MAX 100

void itob(int n,char s[], int base);
void reverse(char s[]);


int main(void)
{
    int number, base;
    char string[MAX];
    
    number = 126224;
    base = 16;

    itob(number,string, base);
    printf("Printing integer %d as a hexadecimal integer: %s", number, string);

    return 0;
}

void itob(int n,char string[], int base)
{
    int i,j,sign;
    sign=n; 
    if (sign < 0)
        n = -n;
    i = 0;
     
     do
    {
        j = n % base;

        string[i++] = (j <= 9)?j+'0':j+'a'-10;
    }while((n/=base)>0);

    if(sign < 0)
        string[i++]='-';
    
    string[i]='\0';
    reverse(string);
}

void reverse(char string[])
{
    int c,i,j;

    for(i=0,j=strlen(string)-1;i<j;i++,j--)
        c=string[i],string[i]=string[j],string[j]=c;
}
    