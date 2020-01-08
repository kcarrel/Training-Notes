#include <stdio.h>
#define MAX_ARRAY 10

void traverse(int *arr) {
    int i;
    for (i = 0; i < MAX_ARRAY; i++) {
        printf("%d \n", arr[i]);
    }
}
void insert(int *arr, int index, int value) {
    int shifted, i;
    shifted = MAX_ARRAY + 1;
    for (i = shifted; i >= index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index - 1] = value;

    for (i = 0; i < shifted; i++) {
        printf("%d \n", arr[i]);
    };
    
}

// To-do: Not sure if there is a way to calculate the changed array size while still deleting "in place" just yet
void delete(int *arr, int index) {
    int j = index + 1, i;
    int o = sizeof(arr);
    if (index <= o) {
        for (i = index; i < MAX_ARRAY; i++) {
            arr[i] = arr[j];
            j++;
        }
        int k = sizeof(arr);
        for (i = 0; i <= k; i++) {
            printf("Index %d: %d \n", i, arr[i]);
        };
    } else {
        printf("The index you have specified is outside of the provide array's range!");
    }

    
}

int search(int *arr, int target) {
    int i;
    for (i = 0; i < MAX_ARRAY; i++) {
        if (arr[i] == target) {
            printf("You target value %d has been found at index %d", target, i);
            return 0;
        }
    }
    printf("Target not found.");
    return 0;
}

void update(int *arr, int index, int value) {
    arr[index] = value;
    traverse(arr);
}

// Todo: touch base with Sasha re Go table tests --> C table tests
// 
void test_insert(int *arr) {
    insert(arr, 11, 2);
    insert(arr, 5, 2000);
    insert(arr, 5, 1000);
}

void test_delete(int *arr) {
    printf("Round 1: \n");
    delete(arr, 1);
    printf("Round 2: \n");
    delete(arr, 1);
    printf("Round 3: \n"); 
    delete(arr, 11);
}

void test_search(int *arr) {
    search(arr, 100);
    search(arr, -100);
    search(arr, 20);
}
void test_update(int *arr) {
    update(arr, 9, 100);
    update(arr, 0, 19);
    update(arr, 100, 9);
    update(arr, 9, 200);

}

int main(void) {
    int ARRAY[MAX_ARRAY], i, val = 0;
    for (i = 0; i < MAX_ARRAY; i++) {
        ARRAY[i] = val;
        val = val + 10;
    }
    test_delete(ARRAY);
    // test_insert(ARRAY);
    // test_search(ARRAY);
    // test_update(ARRAY);
}