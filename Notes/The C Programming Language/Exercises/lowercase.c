#include <stdio.h>
 

void lowercase(char *s);
int main()
{
    char string[150];
 
	printf("What is a string you want to lowercase?: ");
    scanf("%[^\n]s",string);
    
    lowercase(string);
    printf("This is your lowercased string!: %s\n",string);
    return 0;
}

/*check if character is uppercase if so convert using ASCII -- 32!*/
void lowercase(char *s)
{
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=s[i]+32;
        }
        ++i;
    }
}