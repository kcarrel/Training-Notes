#include <stdio.h>
int binsearch(int x, int v[], int n);
/*use a hardcoded array to test binsearch*/
int main(void)
{
    int array[] = {1,2,3,4,5,8,9,10,999999};
    printf("%d", binsearch(10,array,9));
}

/*adjust binsearch to */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;

    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid + 1;
        else 
            low = mid + 1;
        mid = (low + high)/2;
    }
    return x == v[mid] ? mid : -1;

}