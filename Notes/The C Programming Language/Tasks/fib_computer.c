#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 100


int fib_computer(int num)
{
    if (num <= 1)
    {
        return num;
    }
    return fib_computer(num - 1) + fib_computer(num - 2);
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

/* Ask for user input
Format the string of the user input 
Transform string input into an integer
Call fib_computer function that works recursively to find the nth fib number*/
int main(void)
{
    char fib[4], string1[INPUT_SIZE], num[INPUT_SIZE];
    int value;
    printf("Which Fibonacci number would you like to know?\n");
    getinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %s", fib, num);
    value = atoi(num);
    if ( strcmp(fib, "fib") == 0) 
    {
        printf("%d",fib_computer(value));
    } else {
        printf("Please use the correct format of fib number.\n");
    }
}
