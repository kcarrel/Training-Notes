#include <stdio.h>
#define MAX_ARRAY 10

void main() {
    int ARRAY[MAX_ARRAY], i, val = 0;
    for (i = 0; i < MAX_ARRAY; i++) {
        ARRAY[i] = val;
        val = val + 10;
    }

    for (i = 0; i < MAX_ARRAY; i++) {
        printf("%d \n", ARRAY[i]);
    }
}