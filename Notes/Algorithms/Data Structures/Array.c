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

void search(int *arr, int target) {

}

void update(int *arr, int index, int value) {

}

void test_insert() {

}

void test_delete() {

}

void test_search() {

}
void test_update() {

}

int main(void) {
    int ARRAY[MAX_ARRAY], i, val = 0;
    for (i = 0; i < MAX_ARRAY; i++) {
        ARRAY[i] = val;
        val = val + 10;
    }
    delete(ARRAY, 2);
    
}