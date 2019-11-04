#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define INPUT_SIZE 100

/*

ToDo:
- edge cases
- handle unsigned/signed
- what happens with empty input
-very long input
*/

int getinput(char string[], int max);

void bin2dec(int *num){
    int dec = 0, i = 0, remainder;
    while (*num != 0)
    {
        remainder = *num % 10;
        *num /= 10;
        dec += remainder * pow(2, i);
        ++i;
    
    printf("%d",dec);
}

void dec2bin(int *num) {
    int i, temp;
    for (i = 31; i >= 0; i--)
    {
        temp = *num >> i;
        if (temp & 1)
            printf("1");
        else
            printf("0");
    }
}

/* Use case statements to handle the A-F conversion */
void dec2hex(int *num) {
   char hex_result[32];
   int count, i, temp;
   temp = *num;
   count = 0;
   while ( temp > 0)
   {
       switch(temp % 16)
       {
         case 10:
                hex_result[count]='A'; 
                break;
            case 11:
                hex_result[count]='B'; 
                break;
            case 12:
                hex_result[count]='C'; 
                break;
            case 13:
                hex_result[count]='D'; 
                break;
            case 14:
                hex_result[count]='E'; 
                break;
            case 15:
                hex_result[count]='F'; 
                break;
            default:
                hex_result[count]=(temp%16)+0x30;  
       }
       temp = temp/16;
       count++;
   }

   for(i=(count-1); i>=0;i--)
        printf("%c",hex_result[i]);
    
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

