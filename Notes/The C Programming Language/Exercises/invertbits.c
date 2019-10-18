#include <stdio.h>
/*returns x with n bit starting at p inverted */
unsigned invertbits(unsigned x, int p, int n);

int main(void)
{
    printf("%u",invertbits((unsigned)8,(int)3,(int)3));
}

/*

*/
unsigned invertbits(unsigned x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}