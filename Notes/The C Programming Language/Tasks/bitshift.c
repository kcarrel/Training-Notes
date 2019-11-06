#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define INPUT_SIZE 100

int getinput(char string[], int max);
int shift(int bits, char direction, int value);


/* Take in user input
format to bitshift, bits passed, the direction to shift and how many 
*/
int main(void)
{

    char string1[INPUT_SIZE], bitshift[9], bits[50], direction[8], num[INPUT_SIZE];
    int value, bitarray[50];
    getinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %s %s %s", bitshift, bits, direction, num);
    value = atoi(num);
    /* This bit(heheh) is not working */
    bitarray = atoi(bits);
    if ( strcmp(bitshift, "bitshift") == 0) 
    {
        printf("%u", shift(bitarray, direction, value));
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

int shift(int bits, char direction, int value)
{
    if (strcmp(direction, "right") == 0)
    {
        return bits >> value;
    } else if (strcmp(direction, "left") == 0)
    {
        return bits << value;
    }
}