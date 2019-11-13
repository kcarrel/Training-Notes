#include <stdio.h>
#define MAXINPUT 1000

//define variables
int getinput(char line[], int limit);
void reverse(char reversedline[]);
//while input has a length > 0 take the line reverse then print it
int main(void) 
{
    int length;
    char line[MAXINPUT];

    while((length=getinput(line, MAXINPUT))>0)
    {
        reverse(line);
        printf("%s",line);
    }
    return 0;
}

//get the input character, add it into the array, return length
int getinput(char line[], int limit)
{
    int i, c;
    for(i=0;i<limit-1 &&(c=getchar())!=EOF && c != '\n';++i)
        line[i] = c;
    if( c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
//reverse the line by setting temporary variables and switching!
void reverse(char reversedline[])
{
    int i,j;
    char temporary;

    for(i=0;reversedline[i]!='\0';++i)
        ;
    --i;
    if(reversedline[i]=='\n')
    --i;

    j = 0;

    while(j < i)
    {
        temporary = reversedline[j];
        reversedline[j] = reversedline[i];
        reversedline[i] = temporary;
        --i;
        ++j;
    }
}