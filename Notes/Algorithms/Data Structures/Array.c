#include <stdio.h>
#include <stdlib.h>
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

//Create uses malloc to dynamically allocate memory for a specific size
//Returns -1 if allocation fails and pointer to array if allocation succeeds 
int * create() {
    int* ptr;
    int i, val = 0;
    ptr = (int*)malloc(MAX_ARRAY * sizeof(int));

    // if (ptr == NULL) {
    //     return -1;
    // } else {
        for (i = 0; i < MAX_ARRAY; i++) {
            ptr[i] = val;
            val = val + 10;
        }
        return ptr;
    
}

// struct expected {
//     int 1;
//     int 2;
//     int 3;
//     int 4;
//     int 5;
//     int 6;
//     int 7;
//     int 8;
//     int 9;
//     int 10;
// };

//Insert: Inserts a value at the provided index in the given array
// Returns a 0 if successful, -1 if an error occurs and -2 if overflow occurs
int insert(int *arr, int index, int value) {
    int shifted, i;
    int o = sizeof(arr);
    shifted = MAX_ARRAY + 1;
    if (index <= o && index >= 0) {
        for (i = shifted; i >= index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index - 1] = value;
        return SUCCESS;
    } 
    return ERROR;
}

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

//Takes in an array and runs the array with testing insert_values through insert function then uses compare function
//Returns 0 if arrays match and -1 if arrays do not match expectations

void test_insert(int *arr) {
    int i, result;
    for (i = 0; i < 10; i++) {
        result = insert(arr, insert_values[i].index, insert_values[i].value);
        if (result == 0) {
            printf("Round %d: \n", i);
            traverse(arr);
        } else {
            printf("Error has occurred");
            traverse(arr);
        }
    }
}

//Delete: Deletes in-place the value at the provided index in the given array
//Returns a 0 if successfull, -1 if an error occurs and -2 if overflow occurs
int delete(int *arr, int index) {
    int j = index + 1, i;
    int o = sizeof(arr);
    if (index <= o && index >= 0) {
        for (i = index; i < MAX_ARRAY; i++) {
            arr[i] = arr[j];
            j++;
        }
        return SUCCESS;
    } else {
        return ERROR;
    }    
}

struct test_delete {
    int index;
};

struct test_delete delete_index[10] = {
    {11},
    {5},
    {5},
    {29},
    {11},
    {-2},
    {0},
    {1},
    {-6},
    {10}
};

//Takes in an array and runs the array with testing delete_index through delete function then uses compare function
//Returns 0 if arrays match and -1 if arrays do not match expectations

void test_delete(int *arr) {
    int i;
    for (i = 0; i < 10; i++) {
        delete(arr, delete_index[i].index);
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

struct test_search {
    int value;
};

struct test_search search_value[10] = {
    {10},
    {100},
    {5},
    {29},
    {11},
    {-2},
    {0},
    {1},
    {-6},
    {10}
};

//Takes in an array and runs the array with testing search_values through search function then uses compare function
//Returns 0 if arrays match and -1 if arrays do not match expectations

void test_search(int *arr) {
    int i;
    for (i = 0; i < 10; i++) {
        search(arr, search_value[i].value);
    }
}

//Update: Updates the element of an array at a given index to equal the provided value
//Returns a 0 if update is successful or -1 if an error occurs
int * update(int *arr, int index, int value) {
    int o = sizeof(arr);
    if (index <= o && index >= 0) {
        arr[index] = value;
        return 0;
    } 
}

struct test_update {
    //struct expected values;
    int index;
    int value;
};

struct test_update update_value[10] = {
    {11, 2},
    {5, 2000},
    {5, 1000},
    {29, 50000},
    {11, 28},
    {-2, 82},
    {0, 87},
    {1, 222},
    {-6, 2},
    {9, 290}
};

//Takes in an array and runs the array with testing update_values through update function then uses compare function
//Calls compare to verify if the resulting array from update matches the expectation
//Returns 0 if arrays match and -1 if arrays do not match expectations

//To-Do: Either used nested structs to get the expected arrays to send to compare or just use.... arrays?
void test_update() {

    int i,count;
    int *p;
    for (i = 0; i < 10; i++) {
        p = create();
        update(p, update_value[i].index, update_value[i].value);
        //compare(p, second-array);
    }
}

//Takes in the array that has been tested and an array of expected values
//If the two arrays do not match print the difference
//If two arrays match return a SUCCESS value
int compare(int *arr1, int *arr2) {
    int i;
    for (i = 1; i <= MAX_ARRAY; i++) {
        if (arr1[i] != arr2[i]) { 
            printf("Array 1: %d does not match Array 2: %d at index: %d \n", arr1[i], arr2[i], i);
        }
     }
    return SUCCESS;
}


//Main calls table testing functions 
int main(void) {
    test_update();
}