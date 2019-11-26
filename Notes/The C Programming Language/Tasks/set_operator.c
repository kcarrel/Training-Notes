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


void product(int num1, int num2, int num3) 
{
   printf("Do that product thing.");
}

void uni(int num1, int num2, int num3) 
{
   printf("%s", "Do that union thing.");
}

void intersection(int num1, int num2, int num3) {
   printf("%s", "Do that product thing.");
}


/*Note:
Used function name uni instead of union due to reserved word issue
*/
int main(void)
{

    char string1[INPUT_SIZE], compute[INPUT_SIZE], command[INPUT_SIZE];
    int bits[INPUT_SIZE], num[INPUT_SIZE];
    int array1 = 0, array2 = 0, array3 = 0;
    getinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %s", compute, command);
    if ( strcmp(compute, "compute") == 0) {
        if ( strcmp(command, "product") == 0) {
            product(array1, array2, array3);
        } 
        else if( strcmp(command, "union") == 0) {
            uni(array1, array2, array3);
        } 
        else if ( strcmp(command, "intersection") == 0) {
            intersection(array1, array2, array3);
        } 
    } 
    else {
        printf("Program cannot understand input. Please use correct form.\n");
    }
}