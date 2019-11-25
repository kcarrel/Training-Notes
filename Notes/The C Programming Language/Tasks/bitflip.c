#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 100

void flip(int bits, int count, int position);


int getinput(char string[], int max)
{
    int i, c;

    for (i = 0; i < max - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        string[i] = c;
    
    if(c == '\n')
        string[i++] = c;
    
    string[i]='\0';
}

int bin2dec(int *num, int *position){
    int dec = 0, i = 0, count = 0, remainder, value = *position;
    while (*num != 0)
    {
        remainder = *num % 10;
        *num /= 10;
        dec += remainder * pow(2, i);
        ++count;
        ++i;
    }
    flip(dec, count, value);
}


void flip(int bits, int count, int position)
{
    int num = bits;
    int counter = count - 1;
    int i, temp;
    for (i = counter; i >= 0; i--)
    {
        temp = num >> i;
        if (i == position) {
            if (temp & 1)
                printf("0");
            else
                printf("1");
        } else {
            if (temp & 1)
                printf("1");
            else
                printf("0");
        }
    }
}

/* Take in user input, format to decimal, calculate the inverse then print out in binary*/
int main(void)
{

    char string1[INPUT_SIZE], bitflip[INPUT_SIZE];
    int bits[INPUT_SIZE], position[INPUT_SIZE];
    getinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %d %d", bitflip, bits, position);
    if ( strcmp(bitflip, "bitflip") == 0) 
    {
        bin2dec(bits, position);
    } else {
        printf("%s \n", "Program cannot read command given. Please try again.");
    }
}