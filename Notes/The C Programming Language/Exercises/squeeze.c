#include <stdio.h>
#define MAXINPUT 100

int getinput(char string[], int max);
void squeeze(char string1[], char string2[]);

/*  get 2 user inputs
    call squeeze to remove any duplicate chars
    return string 1 without duplicates
*/
int main(void)
{
    char string1[MAXINPUT], string2[MAXINPUT];

    printf("String 1:\n");
    getinput(string1, MAXINPUT);

    printf("String 2:\n");
    getinput(string2, MAXINPUT);

    squeeze(string1, string2);
    printf("%s", string1);
    return 0;
}


/*
    set user input to the correct string array
*/
int getinput(char string[], int max)
{
    int i, c;

    for (i = 0; i < max - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        string[i] = c;
    
    if(c == '\n')
        string[i++] = c;
    
    string[i] = '\0';
}

/*
    take in the two strings and compare strings, remove duplicates from string 1 by shifting chars over and return string 1 up to the last point that there are no dupes 
*/
void squeeze(char string1[], char string2[])
{
    int i, j, k;
    k = 0;

    for(i= 0; string1[i] != '\0'; ++i)
    {
        for(j = 0; (string1[i] != string2[j]) && string2[j]!='\0' ;++j)
            ;
        if(string2[j]=='\0')
            string1[k++] = string1[i];
    }
    
    string1[k]='\0';
}