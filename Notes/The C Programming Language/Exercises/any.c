#include <stdio.h>
#define MAXINPUT 100

/*
function to get user input of strings
then
function to compare the characters in the 2 strings 
*/
int getinput(char string[], int max);
int any(char string1[], char string2[]);

/*
set the strings array size equal to maxinput
set int value
print a request string
get the input for string 1 then string 2

call function any to get the value of the location of the first duplicate character between string 1 and 2
*/
int main(void)
{
    char string1[MAXINPUT], string2[MAXINPUT];
    int value;

    printf("String 1:\n");
    getinput(string1, MAXINPUT);

    printf("String 2:\n");
    getinput(string2, MAXINPUT);

    value = any(string1, string2);
    printf("%d", value);
    return 0;
}


int getinput(char string[], int max)
{
    int i, c;

    for (i = 0; i < max - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        string[i] = c;
    
    if(c == '\n')
        string[i++] = c;
    
    string[i]='\0';
}


int any(char string1[], char string2[])
{
    int i, j, k;
    k = 1;

    for(i= 0; string1[i]!='\0' && (k);)
    {
        for(j = 0; string2[j]!='\0' && (string1[i] != string2[j]);++j)
            ; 
        if(string2[j]=='\0') 
        {
            k = 1;
            i++;
        }
        else 
            k = 0;
    }
    if(string1[i]=='\0')
        return -1;
    else 
        return i;
}