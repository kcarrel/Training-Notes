#include <stdio.h>
#define MAXINPUT 1000

//use pointers to reccreate pstrcat in Chp 2
int getinput(char line[], int limit);
void pstrcat(char *, char *);

int main(void) 
{
    int length;
    char s[MAXINPUT], t[MAXINPUT];

    printf("What is the first string? :");
    getinput(s,MAXINPUT);
    
    printf("What is the second string you would like to concatenate to the first?:");
    getinput(t,MAXINPUT);
    
    pstrcat(s,t);
    printf("%s", s);
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
void pstrcat(char *s, char *t)
{
    //move s to 0 character then append
    while(*s!='\0')
        s++;
    s--;             
    while((*s=*t)!='\0')
    {   
        s++;
        t++;
    }
}
