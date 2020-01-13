#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
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
    for (i = 0; i < MAX_ARRAY; i++) 
    {
        ptr[i] = val;
        val = val + 10;
    }
    return ptr;
    
}

//Takes in the array that has been tested and an array of expected values
//If the two arrays do not match print the difference
//If two arrays match return a SUCCESS value
int compare(int *arr1, int *arr2) {
    traverse(arr1);
    int i;
    for (i = 0; i <= MAX_ARRAY; i++) {
        if (arr1[i] != arr2[i]) { 
            printf("Array 1: %i does not match Array 2: %i at index: %i \n", arr1[i], arr2[i], i);
                traverse(arr2);

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


//Takes in an array and runs the array with testing update_values through update function then uses compare function
//Calls compare to verify if the resulting array from update matches the expectation
//Returns 0 if arrays match and -1 if arrays do not match expectations

//Current Blocker:
//What works: We can use the struct testUpdate *create but need to seperately declare the struct 
//ex: int a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
//struct testUpdate *t1 = createTest(t1,11, 2, a); 
//But that affects the update(p, update_value[i].index, update_value[i].value); loop which relies on the hardcoded values. 
//Currently: Feels like there still needs to be a cumbersome case statement for each loop which is immensely frustrating that I can't just string interpolate because that would fix my issue
// Times 10 which seems needlessly ugly and terrible. 
void test_update() {
    int i;
    int *p;
    for (i = 0; i < 10; i++) {   
    switch (i) {
        case 1:
            p = create();
            int a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
            struct testUpdate *t1 = createTest(t1,11, 2, a); 
            update(p, t1->index, t1->value);
            compare(p, t1->expected);  
            continue;
        case 2:  
            p = create();
            int b[10] = {0, 2, 20, 30, 40, 50, 60, 70, 80, 90};
            struct testUpdate *t2 = createTest(t2,1, 2, b); 
            update(p, t2->index, t2->value);
            compare(p, t2->expected);  
            continue; 
        case 3:  
            p = create();
            int c[10] = {0, 9, 20, 30, 40, 50, 60, 70, 80, 90};
            struct testUpdate *t3 = createTest(t1,2, 9, c); 
            update(p, t3->index, t3->value);
            compare(p, t3->expected);  
            continue; 
        case 4:  
            p = create();
            int d[10] = {0, 10, 20, 30, 40, 50, 60, 70, 90, 90};
            struct testUpdate *t4 = createTest(t4,9, 2000, d); 
            update(p, t4->index, t4->value);
            compare(p, t4->expected);  
            continue; 
        case 5:  
            p = create();
            int e[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 2000};
            struct testUpdate *t5 = createTest(t5,10, 2000, e); 
            update(p, t5->index, t5->value);
            compare(p, t5->expected);  
            continue; 
        case 6:  
            p = create();
            int f[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
            struct testUpdate *t6 = createTest(t6,-2, 2, f); 
            update(p, t6->index, t6->value);
            compare(p, t6->expected);  
            continue; 
        case 7:  
            p = create();
            int g[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
            struct testUpdate *t7 = createTest(t7,-20, 2, g); 
            update(p, t7->index, t7->value);
            compare(p, t7->expected);  
            continue; 
        case 8:  
            p = create();
            int h[10] = {0, 10, 20, 30, 40, 50, 60, 28, 80, 90};
            struct testUpdate *t8 = createTest(t8,8, 28, h); 
            update(p, t8->index, t8->value);
            compare(p, t8->expected);  
            continue; 
        case 9:  
            p = create();
            int i[10] = {0, 10, 20, 30, 2, 50, 60, 70, 80, 90};
            struct testUpdate *t9 = createTest(t9,5, 2, i); 
            update(p, t9->index, t9->value);
            compare(p, t9->expected);  
            continue;
         case 10:  
            p = create();
            int j[10] = {0, 10, 20, 30, 40, 50, 60, 70, 29, 90};
            struct testUpdate *t10 = createTest(t10,9, 29, j); 
            update(p, t10->index, t10->value);
            compare(p, t10->expected);  
            continue;  
        }
    }  
}




//Main calls table testing functions 
int main(void) {
    test_update();
}