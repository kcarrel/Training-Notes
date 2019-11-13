/* return the position of the rightmost occurrence of t in s or -1 if there is none*/
#include <stdio.h>
#define MAXLINE 1000

int getinput(char line[], int max);
int strrindex(char s[], char t[]);


/* find all lines matching pattern*/
int main(void)
{
    char s[] = "abcdedfabcde";
    char t[] = "abc";
    int found = 0;
    // while (getinput(s, MAXLINE) > 0)
    found  = strrindex(s, t);
    printf("Result: %d\n", found);
    }

// /* getinput: get line into s, return length*/
// int getinput(char s[], int lim)
// {
//     int c,i;
//     i = 0;
//     while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
//         s[i++] = c;
//     if (c == '\n')
//         s[i++] = c;
//     s[i] = '\0';
//     return i;
// }

/* strindex: return index of t in s, -1 if none*/
int strrindex(char s[], char t[])
{
    int i, j, k,result;
    result = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
        ;
        if (k > 0 && t[k] == '\0')
            result = i;
    }
    return result;
}