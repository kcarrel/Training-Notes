#include <stdio.h>
#define LIMIT 1000

int getinput(char string[],int limit);
void output(char start[], char end[]);

int main(void)
{
    int length,max;
    char string[LIMIT],maxstring[LIMIT];
    max =0;

    while((length=getinput(string,LIMIT)) > 0)
    {
        if(length > max)
        {
            max = length;
            output(string, maxstring);
        }
    }
    if (max>0)
        printf("Max = %s", maxstring);
}

int getinput(char string[], int limit)
{
    int i,c;
    for(i=0; i < limit -1;++i) {
        c = getchar();
        if (c==EOF)
            break;
        if (c=='\n')
            break;
        string[i] = c;
    }
    if(c == '\n')
    {
        string[i] = c;
        ++i;
    }
    string[i] = '\0';
    return i;
}

void output(char start[],char end[])
{
    int i;
    i=0;
    while((end[i]=start[i]) != '\0')
    ++i;
}