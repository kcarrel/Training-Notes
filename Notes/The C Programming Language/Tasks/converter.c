#include <stdio.h>

void bin2dec(int num){
    printf("%d", num);

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
    char convert[7];
    char input[24];
    int command;
   
    while (input != NULL) {
        printf("What would you like to convert?\n");
        scanf("%s", convert);
        scanf("%s", input);
        scanf("%d", &command);

        /* using if/else instead of case for string because "The C preprocessor is too weak to help us built compile-time expression out of strings" */
        if ( strcmp(input, "bin2dec") == 0) 
        {
            bin2dec(command);
        } 
        else if ( strcmp(input, "dec2bin") == 0)
        {
            dec2bin(command);
        }
        else if ( strcmp(input, "dec2hex") == 0) 
        {
            dec2hex(command);
        } 
        else
        { 
            printf("Please enter a command in the format of 'convert [action] number.\n");
        }
    }
}
