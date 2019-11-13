#include <stdio.h>
#include <string.h>

#define MAXINPUT 1000


int getinput(char line[], int limit);
int pstrend(char *, char *);

int main(void) 
{
    char s[MAXINPUT], t[MAXINPUT];

    printf("What is the first string? : ");
    getinput(s,MAXINPUT);
    
    printf("What is the second string you would like to check? : ");
    getinput(t,MAXINPUT);
    
    printf("%d", pstrend(s,t));
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

int pstrend(char *s, char *t)
{
    s += strlen(s) - 1;
    t += strlen(t) - 1;
    while (*t) {
        if (*t-- != *s--)
    return 0;
    }
    return 1;
}
