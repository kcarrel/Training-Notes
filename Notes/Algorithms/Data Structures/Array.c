#include <stdio.h>
#define MAX_ARRAY 10
#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2

void traverse(int *arr) {
    int i;
    for (i = 0; i < MAX_ARRAY; i++) {
        printf("%d \n", arr[i]);
    }
    //insert traverse
    // for (i = 0; i < shifted; i++) {
    //     printf("%d \n", arr[i]);
    // };

    //delete traverse
    // int k = sizeof(arr);
    //     for (i = 0; i <= k; i++) {
    //         printf("Index %d: %d \n", i, arr[i]);
    //     };
}

//Insert: Inserts a value at the provided index in the given array
// Returns a 0 if successful, -1 if an error occurs and -2 if overflow occurs
int insert(int *arr, int index, int value) {
    int shifted, i;
    shifted = MAX_ARRAY + 1;
    for (i = shifted; i >= index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index - 1] = value;
}

//Delete: Deletes in-place the value at the provided index in the given array
//Returns a 0 if successfull, -1 if an error occurs and -2 if overflow occurs
int delete(int *arr, int index) {
    int j = index + 1, i;
    int o = sizeof(arr);
    if (index <= o) {
        for (i = index; i < MAX_ARRAY; i++) {
            arr[i] = arr[j];
            j++;
        }
        return SUCCESS;
    } else {
        return ERROR;
    }    
}

//Search: Traverses a given array and checks if the target value is present
//Returns a 0 if target is found, -1 if the search is unsuccessful 
int search(int *arr, int target) {
    int i;
    for (i = 0; i < MAX_ARRAY; i++) {
        if (arr[i] == target) {
            return SUCCESS;
        }
    }
    return ERROR;
}

//Update: Updates the element of an array at a given index to equal the provided value
//Returns a 0 if update is successful or -1 if an error occurs
int update(int *arr, int index, int value) {
    int o = sizeof(arr);
    if (index <= o) {
        arr[index] = value;
        return SUCCESS;
    } 
    return ERROR;
}

// Todo: touch base with Sasha re Go table tests --> C table tests
//

struct test_insert {
    int index;
    int value;
};
struct test_insert insert_values[10] = {
    {11, 2},
    {5, 2000},
    {5, 1000},
    {29, 50000},
    {11, 28},
    {-2, 82},
    {0, 87},
    {1, 222},
    {-6, 2},
    {10, 290}
};
void test_insert(int *arr) {
    int i;
    for (i = 0; i < 10; i++) {
        insert(arr, insert_values[i].index, insert_values[i].value);
    }
}

void test_delete(int *arr) {
    delete(arr, 1);
    delete(arr, 1);
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
    update(arr, 200, 9);

}

int compare(int *arr1, int *arr2) {
    int i;
    for (i = 1; i <= MAX_ARRAY; i++) {
        if (arr1[i] != arr2[i]) { 
            return SUCCESS;
        }
     }
    return ERROR;
}

//To-Do: Main creates a dynamic array, loops 10 times to add in element values increasing in 10 each loop
//Calls table testing functions 
int main(void) {
    int ARRAY[MAX_ARRAY], i, val = 0;
    for (i = 0; i < 10; i++) {
        ARRAY[i] = val;
        val = val + 10;
    }
}