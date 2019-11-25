#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 100

int getinput(char string[], int max)
{
    int i, c;

    for (i = 0; i < max - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        string[i] = c;
    
    if(c == '\n')
        string[i++] = c;
    
    string[i]='\0';
}

int bin2dec(int *num){
    int dec = 0, i = 0, remainder;
    while (*num != 0)
    {
        remainder = *num % 10;
        *num /= 10;
        dec += remainder * pow(2, i);
        ++i;
    }
    return dec;
}

void dec2bin(int num) {
    int i, temp;
    for (i = 31; i >= 0; i--)
    {
        temp = num >> i;
        if (temp & 1)
            printf("1");
        else
            printf("0");
    }
}

int shift(int *bits, char *direction, int *value)
{
    int temp = bin2dec(bits);
    int amount = *value;
    int bin;
    if (strcmp(direction, "right") == 0)
    {
        bin = temp >> amount;
    } else if (strcmp(direction, "left") == 0)
    {
        bin = temp << amount;
    }
    dec2bin(bin);
}

/* Take in user input
format to bitshift, bits passed, the direction to shift and how many 
*/
int main(void)
{

    char string1[INPUT_SIZE], bitshift[INPUT_SIZE], direction[INPUT_SIZE];
    int bits[INPUT_SIZE], num[INPUT_SIZE];
    getinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %d %s %d", bitshift, bits, direction, num);
    if ( strcmp(bitshift, "bitshift") == 0) 
    {
        shift(bits, direction, num);
    }
}
