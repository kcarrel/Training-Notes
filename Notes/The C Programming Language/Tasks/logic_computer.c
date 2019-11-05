#include <stdio.h>
#include <string.h>
#define INPUT_SIZE 100

int getinput(char string[], int max);
int compare_or(char arg1[], char arg2[]);
int compare_and(char arg1[], char arg2[]);


int main(void) 
{
    char string1[INPUT_SIZE], logic[INPUT_SIZE], arg1[INPUT_SIZE], command[INPUT_SIZE], arg2[INPUT_SIZE];
    printf("What would you like to logic?\n");
    getinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %s %s %s", logic, arg1, command, arg2);
    if ( strcmp(command, "or") == 0) 
        {
            compare_or(arg1, arg2);
        } 
        else if ( strcmp(command, "and") == 0)
        {
            compare_and(arg1, arg2);
        }
        
        else
        { 
            printf("Please enter a command in the format of 'logic argument1 or/and argument2'.\n");
        }
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

int compare_or(char arg1[], char arg2[])
{
     if ( strcmp(arg1, "true") == 0);
}

int compare_and(char arg1[], char arg2[])
{
     if ( strcmp(arg1, "true") == 0) 
     {
         if ( strcmp(arg2, "true") == 0) 
         {
             printf("true");
         } else {
         printf("false");
        }
     } else if ( strcmp(arg1, "false") == 0) 
     {
        if ( strcmp(arg2, "false") == 0) 
        {
            printf("true");
        } else {
         printf("false");
        }
     }
}