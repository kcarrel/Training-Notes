#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_ARRAY 10
#define ARRAY_BOUNDARY 50
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
    if (index <= ARRAY_BOUNDARY && index >= 0) {
        for (i = shifted; i >= index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index - 1] = value;
        return SUCCESS;
    } 
    return ERROR;
}

struct testInsert {
    int index;
    int value;
    int *expected;
};

struct testInsert *createInsertTest(struct testInsert *t, int indexTest, int valueTest, int expect[]) {
    t->index = indexTest;
    t->value = valueTest;
    t->expected = expect;  
    return t; 
};

//Test-Insert: Takes in an array and runs the array with testing insert_values through insert function then uses compare function
//Returns 0 if arrays match and -1 if arrays do not match expectations
void createTestInsert(int *arr, int index, int value) {
    int *p, result;
    p = create();
    struct testInsert *test = createInsertTest(test, index, value, arr); 
    insert(p, test->index, test->value);
    result = compare(p, test->expected);
    if (result == ERROR) {
        printf("Insert was unsuccessful. \n");
    } else {
        printf("The insert of value %i at index %i was completed successfully. \n", test->value, test->index);
    }
}

//Test_Update: Calls the testsUpdate helper function 10 times to provide the expected array
void createInsertTests() {
    int a[11] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 20};
    createTestInsert(a, 11, 20);
            
    int b[11] = {2, 0, 20, 30, 40, 50, 60, 70, 80, 90};
    createTestInsert(b, 1, 2);
    
    int c[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80};
    createTestInsert(c, -6, 2);
   
    int d[11] = {0, 10, 20, 30, 40, 50, 60, 27, 70, 90};
    createTestInsert(d, 8, 27);
              
    int e[11] = {0, 10, 99, 30, 40, 50, 60, 70, 80, 90};
    createTestInsert(e, 2, 99);
                
    int f[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    createTestInsert(f, -2, 100);
                
    int g[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    createTestInsert(g, -20, 100);
                
    int h[11] = {0, 10, 10, 20, 30, 40, 50, 60, 70, 90};
    createTestInsert(h, 1, 10);
                
    int i[11] = {0, 10, 20, 30, 40, 1000, 60, 70, 80, 90};
    createTestInsert(i, 5, 1000);
                
    int j[10] = {0, 10, 20, 30, 40, 50, 60, 70, 90};
    createTestInsert(j, -20, 8);           
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

struct testDelete {
    int index;
    int *expected;
};

struct testDelete *createDeleteTest(struct testDelete *t, int indexTest, int expect[]) {
    t = malloc(sizeof(*t) + sizeof(int));
    t->index = indexTest;
    t->expected = expect;  
    return t; 
};

//Takes in an array and runs the array with testing delete_index through delete function then uses compare function
//Returns 0 if arrays match and -1 if arrays do not match expectations
void testDelete(int *arr, int index) {
    int *p, result;
    p = create();
    struct testDelete *test = createDeleteTest(test, index, arr); 
    delete(p, test->index);
    result = compare(p, test->expected);
    if (result == ERROR) {
        printf("Delete was unsuccessful. \n");
    } else {
        printf("The value at index %i was completed successfully. \n", test->index);
    }
}

//Test_Update: Calls the testsUpdate helper function 10 times to provide the expected array
void createDeleteTests() {
    int a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    testDelete(a, 11);
            
    int b[10] = {0, 20, 30, 40, 50, 60, 70, 80, 90};
    testDelete(b, 1);
    
    int c[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80};
    testDelete(c, 9);
   
    int d[10] = {0, 10, 20, 30, 40, 50, 60, 70, 90};
    testDelete(d, 8);
              
    int e[10] = {0, 10, 30, 40, 50, 60, 70, 80, 90};
    testDelete(e, 2);
                
    int f[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    testDelete(f, -2);
                
    int g[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    testDelete(g, -20);
                
    int h[10] = {0, 10, 20, 30, 40, 50, 60, 70, 90};
    testDelete(h, 8);
                
    int i[10] = {0, 10, 20, 30, 40, 60, 70, 80, 90};
    testDelete(i, 5);
                
    int j[10] = {0, 10, 20, 30, 40, 50, 60, 70, 90};
    testDelete(j, 8);           
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

struct testSearch{
    int value;
    int expected;
};

struct testSearch search_struct[10] = {
    {10, 0},
    {5, -1},
    {50, 0},
    {29, -1},
    {11, -1},
    {-2, -1},
    {0, 0},
    {1, -1},
    {20, 0},
    {10, 0}
};

int testSearch() {
    int i, result;
    int *p;
    p = create();
    for (i = 0; i < 10; i++) {
        result = search(p, search_struct[i].value);
        if (result == search_struct[i].expected && result == 0) {
            printf("Value %i has been found! \n", search_struct[i].value);
        } else {
            printf("Value %i has not been found! \n", search_struct[i].value);
        }
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
void testsUpdate(int *arr, int index, int value) {
    int *p;
    p = create();
    struct testUpdate *test = createTest(test, index, value, arr); 
    update(p, test->index, test->value);
    compare(p, test->expected);
}

//Test_Update: Calls the testsUpdate helper function 10 times to provide the expected array
void createUpdateTests() {
    int a[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    testsUpdate(a, 11, 2);
            
    int b[10] = {0, 2, 20, 30, 40, 50, 60, 70, 80, 90};
    testsUpdate(b, 1, 2);
    
    int c[10] = {0, 10, 9, 30, 40, 50, 60, 70, 80, 90};
    testsUpdate(c, 2, 9);
   
    int d[10] = {0, 10, 20, 30, 40, 50, 60, 70, 2000, 90};
    testsUpdate(d, 8, 2000);
              
    int e[10] = {0, 10, 2000, 30, 40, 50, 60, 70, 80, 90};
    testsUpdate(e, 2, 2000);
                
    int f[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    testsUpdate(f, -2, 2);
                
    int g[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    testsUpdate(g, -20, 2);
                
    int h[10] = {0, 10, 20, 30, 40, 50, 60, 70, 28, 90};
    testsUpdate(h, 8, 28);
                
    int i[10] = {0, 10, 20, 30, 40, 28, 60, 70, 80, 90};
    testsUpdate(i, 5, 28);
                
    int j[10] = {0, 10, 20, 30, 40, 50, 60, 70, 29, 90};
    testsUpdate(j, 8, 29);           
}


//Main calls table testing functions 

int main(void) {
    createUpdateTests();
    testSearch();
    createDeleteTests();
    createInsertTests();
}