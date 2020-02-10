#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2
#define EMPTY -3
#define TEST 9
#define EXPECTED 10
#define SIZE 10

// Hash struct
typedef struct Item {
    int key;
    int value;
} Item;

//create global testHash and expectedHash for testFunctions to use
Item* testHash[SIZE];
Item* expectedHash[SIZE];

void traverse() {
    for (int i = 0; i < SIZE; i++) {
        int value = testHash[i]->value;
        int key = testHash[i]->key;        
        printf("Test Key: %d Value: %d \n", key, value);
    }
    for (int i = 0; i < SIZE; i++) {
        int value = expectedHash[i]->value;
        int key = expectedHash[i]->key;
        printf("Expected Key: %d Value: %d \n", key, value);
    }
}

//compare checks the Items
bool compare() {
    for (int i = 0; i < SIZE; i++) {
        int testKey = testHash[i]->key;
        int testValue = testHash[i]->value;
        int expectedKey = expectedHash[i]->key;
        int expectedValue = expectedHash[i]->value;
        if (testKey != expectedKey || testValue != expectedValue) {
            return false;
        }
    }
    return true;
}

int hashing(int key) {
    return key % SIZE;
}
// creates a new Item struct
// returns new struct
Item * createItem(int key, int value, int success) {
    Item * item = malloc(sizeof(Item));
    if (item == NULL) {
    } else {
        item->key = key;
        item->value = value;
        success = SUCCESS;
        return item;
    }
}

// insert takes in a key and value
// calls a helper function to create an Item struct with the provided key and value
// adds the new Item to the hashTable
// if the expected value is in the hashTable at the expected key then returns a success code
void insert(int type, int key, int value, int success) {
    if (type == TEST) {
        testHash[key] = createItem(key, value, success);
        if (testHash[key]->value != value) {
            success = ERROR;
        }
        
    } else if (type == EXPECTED) {
        expectedHash[key] = createItem(key, value, success);
        if (expectedHash[key]->value != value) {
            success = ERROR;
        }
    }
}

int testInsert() {
    return ERROR;
}

void buildInsertTests() {
    //InsertTests
    // 5 passes
    // 5 Fails
    // Empty Array
    // Too large for hash table
    // Collision
    // Full Hash Table
}
//To-do: will need to think of how to handle collisions 
// buildHashTable receives an array of keys and an array of values
// key[i] will be mapped to value[i] when building the hashTable
// loops through the values to create a key for the current value then inserts it into the existing hashTable.
// returns a SUCCESS code if all values are added into the hashTable successfully 
int buildHashTable(int type, int *keys, int *values) {
    int errcode = SUCCESS;
    for (int i = 0; i < SIZE; i++) {
        int key = hashing(keys[i]);
        insert(type, key, values[i], errcode);
   }
   return errcode;
}

//to-do: Will need to think of a rescue in the case of a collision insertion
// searchHashTable takes in an integer key
// calls the helper function to hash the received key to correspond to an expected index within the hash table
// if the key at the position in the test hashTable indicated by the hashing function matches the received key then return a SUCCESS code
// if a mistmatch occurs return an ERROR code
int searchHashTable(int type, int key, int * success) {
    if (key > SIZE || key < 0) return ERROR;
    int hashIndex = hashing(key);
    if (testHash[hashIndex]->key == key) {
        *success = SUCCESS;
    }
}

int testSearch(int key, int expectedOutcome) {
    //build the testHash
    int keys[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value[10]= { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    buildHashTable( 9, keys, value);
    int success = ERROR;
    searchHashTable(9, key, &success);
    if (success == SUCCESS && expectedOutcome == SUCCESS) {
        printf("The key %d was successfully found as expected. \n", key);
        return SUCCESS;
    } else if (success == ERROR && expectedOutcome == ERROR) {
        printf("The key %d was not found as expected. \n", key);
        return SUCCESS;
    }
    printf("Mismatch: An unknown error has occurred. \n");
    return ERROR;
}

void buildSearchTests() {
printf("Build Search Test Passes: \n");
    testSearch(1, SUCCESS);
    testSearch(8, SUCCESS);
    testSearch(3, SUCCESS);
    testSearch(4, SUCCESS);
    testSearch(9, SUCCESS);

    //5 Fail
    printf("Build Search Test Fails: \n");
    testSearch(99, ERROR);
    testSearch(-9, ERROR);
    testSearch(11, ERROR);
    testSearch(20, ERROR);
    testSearch(-20, ERROR);
}

//To-do: Like above need to make adjustments based on potential insertion collisions messing up the hashing function
// Also saw an alternative way to do delete is just to set the key to -1?
// deleteItem takes in an Item struct
// finds the key of the provided Item then passes it to the helper function to hash it and find the corresponding index
// if the key at the position in the hashTable indicated by the hashing function matches the received key then sets an empty delete Item equal to the Item at the hashIndex
// if a failure occurs return an ERROR code
void deleteItem(int key, int * success) {
    int hashIndex = hashing(key);
    if (testHash[hashIndex]->key == key) {
        free(testHash[hashIndex]);
        insert(9, key, NULL, *success);
        *success = SUCCESS;
    }
}

//need to make a clear hashTable function? 
// Stopping point: testing for delete is failing need to figure out why the expectedKeys aren't being inserted into the expectedTable 
int testDelete(int key, int *expectedKeys, int *expectedValues) {
    int keys[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value[10]= { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    buildHashTable( 9, keys, value);
    buildHashTable( 10, expectedKeys, expectedValues);
    int success = ERROR;
    deleteItem(key, &success);
    if (success == SUCCESS && compare()) {
        printf("The key %d was deleted successfully found as expected. \n", key);
        return SUCCESS;
    } 
    printf("The key %d could not be deleted successfully as expected. \n", key);
    return ERROR;
}


void buildDeleteTests() {
    printf("Build Delete Test Passes: \n");
    int testKeys1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int testValues1[10] = { 0, 20, 30, 40, 50, 60, 70, 80 , 90, 100};
    testDelete(1,testKeys1, testValues1);

    int testKeys2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int testValues2[10] = {10, 20, 30, 40, 50, 60, 70, 0, 90, 100};
    testDelete(8,testKeys2,testValues2);

    int testKeys3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int testValues3[10] = {10, 0, 30, 40, 50, 60, 70, 80 , 90, 100};
    testDelete(2,testKeys3, testValues3);

    int testKeys4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int testValues4[10] = {10, 20, 30, 40, 0, 60, 70, 80 , 90, 100};
    testDelete(5,testKeys4, testValues4);

    int testKeys5[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int testValues5[10] = {10, 20, 0, 40, 50, 60, 70, 80 , 90, 100};
    testDelete(3,testKeys5, testValues5);

    //5 Fail
    printf("Build Delete Test Fails: \n");
    int testKeys6[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int testValues6[10] = {10, 20, 30, 40, 50, 60, 70, 80 , 90, 100};
    testDelete(-10,testKeys6, testValues6);

    int testKeys7[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int testValues7[10] = {10, 20, 30, 40, 50, 60, 70, 80 , 90, 100};
    testDelete(50,testKeys7, testValues7);
  
}

void main() {
   buildSearchTests();
   buildDeleteTests();
}