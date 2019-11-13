#include <stdio.h>
#define MAXINPUT 100

int getinput(char string[], int limit);
void expand(char s1[], char s2[]);


/*get input s1 and expand short hand notations into s2 then print*/
int main(void)
{   char s1[MAXINPUT], s2[MAXINPUT];

    getinput(s1, MAXINPUT);
    expand(s1, s2);

    printf("Expanded string: %s", s2);

    return 0;
}

int getinput(char s1[], int limit)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c=getchar()) != EOF; ++i)
        s1[i] = c;    
    s1[i]='\0';
}

void expand(char s1[], char s2[])
{
    int i, j, c;
    i = 0;
    j = 0;
    while ((c = s1[i++]) != '\0')
        {
            if (s1[i] == '-' && s1[i + 1] >= c)
            {
                i++;
                while (c < s1[i])
                    s2[j++] = c++;
            }
            else
                s2[j++] = c;
            s2[j] = '\0';
        }
}