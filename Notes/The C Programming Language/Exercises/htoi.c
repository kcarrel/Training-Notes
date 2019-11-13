#include <stdio.h>
#define MAXINPUT 100
#define YES 1
#define NO 0

int getinput(char line[],int limit);
int htoi(char string[]);


/*main calls get input to take in user input
converts the value in htoi(hex to integer) then prints the outcome*/
int main(void)
{
    char line[MAXINPUT];
    int value;
        
    getinput(line, MAXINPUT);
    value = htoi(line); 
    printf("%s is %d",line,value);
    
    return 0;
}

/* pass in an empty array with a limit equal to 100
    declare variabes to ++ to in order to move through the string
    fill string array in with input
*/
int getinput(char string[],int limit)
{
    int c,i;

    for(i=0;i< limit - 1 &&(c=getchar())!=EOF && c!='\n';++i)
        string[i] = c;
    if(c=='\n')
    {
        string[i] =c;
        ++i;
    }
    string[i] = '\0';

    return i;
}

/* take in the user input
    remove any optional characters 0x
    iterate through the string
    if the character is valid 0 - 9 or a-f then account for it and continue
    return the integer translated!
*/
int htoi(char string[])
{
    int hexdigit,i,inhex,n;
    i = 0;
    if( string[i] == '0')
    {
        ++i;
        if(string[i] == 'x' || string[i] == 'X')
            ++i;
    }
    
    n = 0;
    inhex = YES;

    for(;inhex==YES;++i)
    {
        if(string[i] >='0' && string[i] <='9')
            hexdigit= string[i] - '0';
        else if(string[i] >='a' && string[i] <='f')
            hexdigit= string[i] -'a' + 10;
        else if(string[i] >='A' && string[i] <='F')
            hexdigit= string[i] -'A' + 10;
        else
            inhex = NO;
        
        if(inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;
}
    