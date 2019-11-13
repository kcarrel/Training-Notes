#include <stdio.h>
/* returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.*/
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
    printf("%d\n",setbits((unsigned)93,4,3,(unsigned)211));
}

/*

*/
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x & ~(~(~0 << n) << (p+1-n)) | ( ~(~0<<n) & y) << (p+1-n);
}