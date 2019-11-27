#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define INPUT_SIZE 100

int getstringinput(char string[], int max)
{
    int i, c;

    for (i = 0; i < max - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
        string[i] = c;
    
    if(c == '\n')
        string[i++] = c;
    
    string[i]='\0';
}

/* Only allows 1 digit atm*/
int getintinput(int arr[], int max)
{
    int i, c;

    for (i = 0; i < max - 1 && (c=getchar()) != EOF && c != '\n';)
        if (isdigit(c)) {
            arr[i] = c;
            i++;
        }
    
    if(c == '\n')
        arr[i++] = c;
    
    arr[i]='\0';
}

/* To-do: Grossly inefficient without a set or hash table being used but not incredibly familiar with those in C atm.*/

void product(int *num1, int *num2, int *num3) 
{   
    int i,j,k, count = 0;
    int m = sizeof(num1)/sizeof(num1[0]), n = sizeof(num2)/sizeof(num2[0]), o = sizeof(num3)/sizeof(num3[0]);
    m ++, n++, o++;
    int outcomes = m * n * o, results[outcomes];
    printf("The product of the three arrays is: \n");
    while (count < outcomes)
    {
        for(i = 1; i < m; i++) {
            for(j = 1; j < n; j++) {
                for(k= 1; k < o; k++) {
                    printf("{%c, %c, %c} \n", num1[i], num2[j], num3[k]);
                            count++;

                } 
            }
        }
    }

}

/* Todo: Make this code less gross and sad 
    Need to think of a better way to pull out duplicated numbers
    Maybe a helper function to sanitize results before printing
*/
void uni(int *num1, int *num2, int *num3) 
{
    int results[INPUT_SIZE];
    int i,j,k;
    int m = sizeof(num1)/sizeof(num1[0]), n = sizeof(num2)/sizeof(num2[0]);
    m++, n++;
    int mSize = m + n;

    for(i = 0; i < m; i++)
    {
        results[i] = num1[i];
    }
    for(i = 0, j = m; j < mSize && i < n; i++, j++)
    {
        results[j] = num2[i];
    } 

    int o = sizeof(num3)/sizeof(num3[0]);
    o++;
    int msSize = mSize + o;
    for(i = 0, k = mSize; k < msSize && i < o; i++, j++, k++)
    {
        results[k] = num3[i];
    } 
    printf("The union of the three arrays is: \n");
    for (i = 0; i < msSize; i++)
    {
    printf("%c ", results[i]);
    }
}



void compare(int *num1, int *num2, int *results)
{
    int i = 0,j = 0, k = 0;;
    int m = sizeof(num1)/sizeof(num1[0]);
    int n = sizeof(num2)/sizeof(num2[0]);
    m++;
    n++;
    while (i < m && j < n)
    {
        if (num1[i] < num2[j])
            i++;
        else if (num2[j] < num1[i])
            j++;
        else /* found a duplicate */
        {
            results[k] = num2[j++];
            i++;
            k++;
        }
    }
}

void intersection(int *num1, int *num2, int *num3) {
    int results1[INPUT_SIZE], results2[INPUT_SIZE], i;
    compare(num1, num2, results1);
    compare(results1, num3, results2);
    printf("The intersection of the three arrays: \n");
    for (i = 0; i < 5; i++)
    {
        printf("%c ", results2[i]);
    }
}

int printIntersection(int arr1[], int arr2[], int m, int n) 
{ 
  int i = 0, j = 0; 
  while (i < m && j < n) 
  { 
    if (arr1[i] < arr2[j]) 
      i++; 
    else if (arr2[j] < arr1[i]) 
      j++; 
    else /* if arr1[i] == arr2[j] */
    { 
      printf(" %d ", arr2[j++]); 
      i++; 
    } 
  } 
} 

/* sort arrays */
void sort(int *nums)
{
    int i,a, j;
    int n = sizeof(nums)/sizeof(nums[0]);
    n++;
    for (i = 0; i < n; ++i) 
        for (j = i + 1; j < n; ++j)
            {
                if (nums[i] > nums[j]) 
                {
                    a =  nums[i];
                    nums[i] = nums[j];                
                    nums[j] = a;

                }
            }
}
    
int handle_arrays(char *command)
{
    int array1[INPUT_SIZE], array2[INPUT_SIZE], array3[INPUT_SIZE];

    printf("What is the first array? \n");
    getintinput(array1, INPUT_SIZE);
    sort(array1);

    printf("What is the second array? \n");
    getintinput(array2, INPUT_SIZE);
    sort(array2);

    printf("What is the third array? \n");
    getintinput(array3, INPUT_SIZE);
    sort(array3);

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

/*Note:
Used function name uni instead of union due to reserved word issue
Doing the program to only take in one prompt as specified "compute union|product|intersection "array1" "array2" "array3""
became very messy for reading user input so switched to a different mode of taking in the arrays after prompts
Old reading user input:     sscanf(string1,"%s %s %*c%[^\"]%*c %*c%[^\"]%*c %*c%[^\"]", compute, command, array1, array2, array3);

Union: Set of all things in A OR in B(or both)
Intersection: Set of all things in both A and B.
*/
int main(void)
{

    char string1[INPUT_SIZE], compute[INPUT_SIZE], command[INPUT_SIZE];
    printf("What would you like to compute? Ex: compute union \n");
    getstringinput(string1, INPUT_SIZE);
    sscanf(string1,"%s %s", compute, command);
    if ( strcmp(compute, "compute") != 0) {
        printf("Program cannot understand input. Please use correct form.\n");        
    } else {
        handle_arrays(command);
    }    
}