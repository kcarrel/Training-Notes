#include <stdio.h>
#include <string.h>
#define INPUT_SIZE 100

int getinput(char string[], int max);

int main(void) 
{
    char string1[INPUT_SIZE], logic[INPUT_SIZE], arg1[INPUT_SIZE], command[INPUT_SIZE], arg2[INPUT_SIZE];
    printf("What would you like to logic?\n");
    getinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %s %s %s", logic, arg1, command, arg2);
    if ( strcmp(command, "or") == 0) 
        {
            printf("POC or");
        } 
        else if ( strcmp(command, "and") == 0)
        {
            printf("POC and");
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

