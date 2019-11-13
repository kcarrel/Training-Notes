#include <stdio.h>

void reverse(char *str)
{
    if (*str)
    {
        reverse(str+1);
        printf("%c", *str);
    }
}

int main(void)
{
    char phrase[] = "This is a phrase to revserse";
    reverse(phrase);
}


