#include <stdio.h>

/*define the macro
user temporary variable _t of type t (passed in argument)
and use swap x and y
*/
#define swap(t,x,y) { t _t; \
    _t = x;\
    x = y;\
    y = _t; }

int main(void)
{
    char x, y;                                 
    x='k';
    y='t';
    printf("Before swap x equals %c and y equals %c\n",x,y);
    swap(char,x,y);
    printf("After swap x equals %c and y equals %c\n",x,y);
}