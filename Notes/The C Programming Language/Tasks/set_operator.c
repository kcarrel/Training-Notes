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


void product(char *num1, char *num2, char *num3) 
{   
    printf("Num1: %s \n", num1);
    printf("Num2: %s \n", num2);
    printf("Num3: %s \n", num3);

    printf("Do that product thing.");
}

void uni(char *num1, char *num2, char *num3) 
{
    printf("Num1: %s \n", num1);
    printf("Num2: %s \n", num2);
    printf("Num3: %s \n", num3);
    printf("%s", "Do that union thing.");
}

void intersection(char *num1, char *num2, char *num3) {
    printf("Num1: %s \n", num1);
    printf("Num2: %s \n", num2);
    printf("Num3: %s \n", num3);
    printf("%s", "Do that product thing.");
}


/*Note:
Used function name uni instead of union due to reserved word issue
*/
int main(void)
{

    char string1[INPUT_SIZE], compute[INPUT_SIZE], command[INPUT_SIZE], array1[INPUT_SIZE], array2[INPUT_SIZE], array3[INPUT_SIZE];
    int bits[INPUT_SIZE], num[INPUT_SIZE];
    getinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %s %*c%[^\"]%*c %*c%[^\"]%*c %*c%[^\"]", compute, command, array1, array2, array3);
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