#include <stdio.h>
#define MAXINPUT 100

int getinput(char line[],int limit);
void escapechars(char string[], char temp[]);
/*Take in user input in the form of a temporary string 
then call escapechars to scan the temporary string for any '\t' and '\n' 
convert/add to string to print after hitting EOF*/
int main(void)
{
    char string[MAXINPUT], temp[MAXINPUT];
    getinput(temp, MAXINPUT);

    escapechars(string, temp);
    printf("%s", string);

}

int getinput(char temp[], int limit)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c=getchar()) != EOF; ++i)
        temp[i] = c;    
    temp[i]='\0';
}

void escapechars(char string[], char temp[])
{
    int i, j;
    i = 0;
    j = 0;
    while (temp[i] != '\0')
    {
        switch(temp[i])
        {
            case '\t':
                string[j]='\\';
                ++j;
                string[j]='t';
                break;
            case '\n':
                string[j]='\\';
                ++j;
                string[j]='n';
                break;
            default:
                string[j] = temp[i];
                break;
        }
        ++i;
        ++j;
    }
    string[j]='\0';
}