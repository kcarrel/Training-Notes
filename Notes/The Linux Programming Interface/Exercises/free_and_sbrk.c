#define _BSD_SOURCE
#define _DEFAULT_SOURCE
#include <stdlib.h>
#include <string.h>

#include <malloc.h>
#include <unistd.h>

#define MAX_ALLOCS 1000000

int main(int argc, char *argv[]) {
    char *ptr[MAX_ALLOCS];
    int freeStep, freeMin, freeMax, blockSize, numAllocs, j;
    void *previous_sbrk, *current_sbrk;

    printf("\n");

    if (argc < 3 || strcmp(argv[1], "--help") == 0) {
        printf("%s num-allocs block-size [step [min [max]]]\n", argv[0]);
        return EXIT_FAILURE;
    }

    numAllocs = atoi(argv[1]);
    if (numAllocs > MAX_ALLOCS) {
        printf("num-allocs > %d\n", MAX_ALLOCS);
        exit(EXIT_FAILURE);
    }

    blockSize = atoi(argv[2]);
    freeStep = (argc > 3) ? atoi(argv[3]) : 1;
    freeMin =  (argc > 4) ? atoi(argv[4]) : 1;
    freeMax =  (argc > 5) ? atoi(argv[5]) : numAllocs;

    if (freeMax > numAllocs) {
        printf("free-max > num-allocs\n");
        exit(EXIT_FAILURE);
    }

    printf("Initial program break:          %10p\n", (void *)sbrk(0));
    printf("Allocating %d*%d bytes\n", numAllocs, blockSize);
    previous_sbrk = 0;
    for (j = 0; j < numAllocs; j++) {
        current_sbrk = sbrk(0);
        ptr[j] = malloc(blockSize);
        if (current_sbrk != previous_sbrk) {
            printf("\033[0;34m*** %10p\033[0m\n", (void*)current_sbrk);
        } else {
            printf(">>> %10p\n", (void *)current_sbrk);
        }
        previous_sbrk = current_sbrk;
        if (ptr[j] == NULL) {
            printf("malloc");
            exit(EXIT_SUCCESS);
        }
    }

    printf("Program break is now:           %10p\n", (void *)sbrk(0));

    printf("Freeing blocks from %d to %d in steps of %d\n",
                freeMin, freeMax, freeStep);
    for (j = freeMin - 1; j < freeMax; j += freeStep)
        free(ptr[j]);

    printf("After free(), program break is: %10p\n", (void *)sbrk(0));

    exit(EXIT_SUCCESS);
}