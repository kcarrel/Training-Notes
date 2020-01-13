#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_ARRAY 10
#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2


void traverse(int *arr) {
    int i;
    for (i = 0; i < MAX_ARRAY; i++) {
        printf("%d \n", arr[i]);
    }
}

//Create uses malloc to dynamically allocate memory for a specific size
//Returns -1 if allocation fails and pointer to array if allocation succeeds 
int * create() {
    int* ptr;
    int i, val = 0;
    ptr = (int*)malloc(MAX_ARRAY * sizeof(int));
    for (i = 0; i < MAX_ARRAY; i++) 
    {
        ptr[i] = val;
        val = val + 10;
    }
    return ptr;
    
}

//Compare: Takes in the array that has been tested and an array of expected values
//If the two arrays do not match print the difference
//If two arrays match return a SUCCESS value
int compare(int *arr1, int *arr2) {
    // traverse(arr1);
    int i;
    for (i = 0; i < MAX_ARRAY; i++) {
        if (arr1[i] != arr2[i]) { 
            printf("Array 1: %i does not match Array 2: %i at index: %i \n", arr1[i], arr2[i], i);
            return ERROR;
        }
     }
    return SUCCESS;
}


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

//Test-Insert: Takes in an array and runs the array with testing insert_values through insert function then uses compare function
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


struct testUpdate {
    int index;
    int value;
    int *expected;
};
struct testUpdate *createTest(struct testUpdate *t, int indexTest, int testValue, int expect[]) {
    t = malloc(sizeof(*t) + sizeof(int));
    t->index = indexTest;
    t->value = testValue;
    t->expected = expect;  
    return t; 
};



//Update_mod: takes in an expected array, index and value 
//Creates a testUpdate structure using the  provided expected array, index and values
//Calls update with the provided index and values 
//Calls compare to verify if the resulting array from update matches the expectation
//Returns 0 if arrays match and -1 if arrays do not match expectations
void test_update(int *arr, int index, int value) {
    int *p;
    p = create();
    struct testUpdate *test = createTest(test, index, value, arr); 
    update(p, test->index, test->value);
    compare(p, test->expected);
}

//Test_Update: Calls the test_update helper function 10 times to provide the expected array
void create_update_tests() {
    int a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    test_update(a, 11, 2);
            
    int b[10] = {0, 2, 20, 30, 40, 50, 60, 70, 80, 90};
    test_update(b, 1, 2);
    
    int c[10] = {0, 10, 9, 30, 40, 50, 60, 70, 80, 90};
    test_update(c, 2, 9);
   
    int d[10] = {0, 10, 20, 30, 40, 50, 60, 70, 2000, 90};
    test_update(d, 8, 2000);
              
    int e[10] = {0, 10, 2000, 30, 40, 50, 60, 70, 80, 90};
    test_update(e, 2, 2000);
                
    int f[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    test_update(f, -2, 2);
                
    int g[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    test_update(g, -20, 2);
                
    int h[10] = {0, 10, 20, 30, 40, 50, 60, 70, 28, 90};
    test_update(h, 8, 28);
                
    int i[10] = {0, 10, 20, 30, 40, 28, 60, 70, 80, 90};
    test_update(i, 5, 28);
                
    int j[10] = {0, 10, 20, 30, 40, 50, 60, 70, 29, 90};
    test_update(j, 8, 29);
               
}


//Main calls table testing functions 
int main(void) {
    create_update_tests();
}