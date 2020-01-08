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

void delete(int *arr, int index) {
    int j = index + 1, i;
    for (i = index; i < MAX_ARRAY; i++) {
       arr[i] = arr[j];
       j++;
    }

    for (i = 0; i < MAX_ARRAY - 1; i++) {
        printf("%d \n", arr[i]);
    };
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
    printf("round 1");
    delete(arr, 1);
    printf("round 2");
    delete(arr, 1);
    printf("round 3"); 
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
    test_insert(ARRAY);
    test_search(ARRAY);
    test_update(ARRAY);
}