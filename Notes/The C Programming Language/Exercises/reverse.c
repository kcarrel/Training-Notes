#include <stdio.h>
#define MAXINPUT 1000

int getinput(char line[], int limit);
void reverse(char reversedline[]);

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