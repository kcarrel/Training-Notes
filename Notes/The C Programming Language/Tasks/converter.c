#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INPUT_SIZE 100

int getinput(char string[], int max);

void bin2dec(int *num){
    int dec = 0, i = 0, remainder;
    while (*num != 0)
    {
        remainder = *num % 10;
        *num /= 10;
        dec += remainder * pow(2, i);
        ++i;
    }
    printf("%d",dec);
}

void dec2bin(int *num) {
    int i, c, k;
    for (i = 31; i >= 0; i--)
    {
        k = *num >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
}

void dec2hex(int *num) {
    printf("POC you are converting dec2hex \n");
}

int main(void) 
{
    char string1[INPUT_SIZE], convert[INPUT_SIZE], command[INPUT_SIZE];
    int input[INPUT_SIZE];
    int value;
   
    printf("What would you like to convert?\n");
    getinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %s %d", convert, command, input);

     /* using if/else instead of case for string because "The C preprocessor is too weak to help us built compile-time expression out of strings" */
     if ( strcmp(command, "bin2dec") == 0) 
        {
            bin2dec(input);
        } 
        else if ( strcmp(command, "dec2bin") == 0)
        {
            dec2bin(input);
        }
        else if ( strcmp(command, "dec2hex") == 0) 
        {
            dec2hex(input);
        } 
        else
        { 
            printf("Please enter a command in the format of 'convert [action] number.\n");
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

