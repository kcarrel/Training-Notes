#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXSTORAGE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int getline(char *line[], int limit);

void qsort(char *lineptr[], int left, int right);
/* sort input lines*/
main()
{
    int nlines;
    char linestorage[MAXSTRORAGE];
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {                            
        printf("error: input too big to sort\n");
        return 1;
    }
}

int getline(char *line[], int limit)
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

#define MAXLEN 1000
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}