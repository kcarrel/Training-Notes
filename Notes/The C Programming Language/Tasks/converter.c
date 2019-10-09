#include <stdio.h>

void bin2dec(){
    printf("POC you are converting bin2dec \n");
}

void dec2bin() {
    printf("POC you are converting dec2bin \n");
}

void dec2hex() {
    printf("POC you are converting dec2hex \n");
}

void main() 
{
    char input[100];
    while (input != NULL) {
        printf("What would you like to convert?\n");
        scanf("%s", input);

        /* using if/else instead of case for string because "The C preprocessor is too weak to help us built compile-time expression out of strings" */
        if ( strcmp(input, "bin2dec") == 0) 
        {
            bin2dec();
        } 
        else if ( strcmp(input, "dec2bin") == 0)
        {
            dec2bin();
        }
        else if ( strcmp(input, "dec2hex") == 0) 
        {
            dec2hex();
        } 
        else
        { 
            printf("%s", input);
            printf("Please enter a real command ya fool.");
        }
    }
}
