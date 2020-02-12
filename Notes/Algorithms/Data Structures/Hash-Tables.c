#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2

#define SIZE 10
#define LIMIT 100

// Hash Item struct
typedef struct Item {
    int key;
    int value;
} Item;

//Hash Table struct
typedef struct HashTable {
    int size;
    Item** items;
} HashTable;

// traverse function is for visual confirmation of differences between hashTables when building functionality. 
// will delete after changing structure is completed 
//void traverse(HashTable * testHash) {
//     for (int i = 0; i < SIZE; i++) {
//         int value = testHash->items[i]->value;
//         int key = testHash->items[i]->key;        
//         printf("Test Key: %d Value: %d \n", key, value);
//     }

// }


//compare checks the testHash and expectedHash for parity
// if the two HashTables match returns true
// if a mismatch occurs returns false
bool compare(HashTable * testHash, HashTable * expectedHash) {
    for (int i = 0; i < SIZE; i++) {
        int testKey = testHash->items[i]->key;
        int testValue = testHash->items[i]->value;
        int expectedKey = expectedHash->items[i]->key;
        int expectedValue = expectedHash->items[i]->value;
        if (testKey != expectedKey || testValue != expectedValue) {
            return false;
        }
    }
    return true;
}

// hashing takes in a key
// returns a "hashed" index based on the SIZE of the hashTable
int hashing(int key) {
    return key % SIZE;
}

// creates a new Item struct
// returns new struct
Item * createItem(int key, int value, int * success) {
    Item * item = malloc(sizeof(Item));
    if (item != NULL) {        
        item->key = key;
        item->value = value;
        *success = SUCCESS;
        return item;
    }
    return NULL;
}

// creates a new HashTable struct
// returns new HashTable struct
HashTable * createHashTable(int size) {
    if (size < 1 || size > LIMIT) return NULL;
    HashTable * hashTable = malloc(sizeof(HashTable));
    hashTable->items = malloc(sizeof(Item) * size);
    if (hashTable == NULL || hashTable->items == NULL) {
        return NULL;
    }
    hashTable->size = size;
    for (int i = 0; i < size; i++) {
        hashTable->items[i] = NULL;
    }
    return hashTable;
}


// insert takes in a key and value
// calls a helper function to create an Item struct with the provided key and value
// adds the new Item to the hashTable
// if the expected value is in the hashTable at the expected key then returns a success code
int insert(HashTable * hashTable, int key, int value) {
    int success = ERROR;
    hashTable->items[key] = createItem(key, value, &success);
    if (hashTable->items[key]->value != value) {
        return ERROR;
    }
    return success;
}

// bulkInsert receives an array of keys and an array of values
// key[i] will be mapped to value[i] when building the hashTable
// loops through the values to create a key for the current value then inserts it into the existing hashTable.
// returns a SUCCESS code if all values are added into the hashTable successfully 
int bulkInsert(HashTable * hashTable, int *keys, int *values) {
    int success = ERROR;
    for (int i = 0; i < SIZE; i++) {
        int key = hashing(keys[i]);
        success = insert(hashTable , key, values[i]);
    }
   return success;
}

//returns a HashTable struct to use for testing 
HashTable * createTestHashTable() {
    int keys[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int value[10]= { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    HashTable * testHash = createHashTable(10);
    bulkInsert(testHash, keys, value);
    return testHash;
}

// searchHashTable takes in an integer key and a type
// calls the helper function to hash the received key to correspond to an expected index within the hash table
// if the key at the position in the test hashTable indicated by the hashing function matches the received key then return a SUCCESS code
// if a mistmatch occurs return an ERROR code
int searchHashTable(HashTable * hashTable, int key) {
    if (key > SIZE || key < 0) return ERROR;
    int hashIndex = hashing(key);
    if (hashTable->items[hashIndex]->key == key) {
        return SUCCESS;
    }
    return ERROR;
}


// testSearch
// First creates a testHash with the testing key/value pairs. 
// calls the helper function searchHashTable on the testHash
// if the key/value pair is found successfully and the expectedOutcome matches a SUCCESS code 0 is returned then a success message is printed and a SUCCESS code is returned
// if the value is not found then a failure message is printed and an ERROR -1 is returned
int testSearch(int key, int expectedOutcome) {
    HashTable * testHash = createTestHashTable();
    int success = searchHashTable(testHash, key);
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

// buildSearchTests
// creates 5 test cases expected to pass the testSearch function
// creates 5 test cases (out of range) expected to fail the testSearch function
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

// deleteItem takes in a key to delete and an int to signify success of deletion
// finds the key of the provided Item then passes it to the helper function to hash it and find the corresponding index
// if the key at the position in the hashTable indicated by the hashing function matches the received key then sets an empty delete Item equal to the Item at the hashIndex
// if a failure occurs then the success code remains as ERROR
// void deleteItem(HashTable * hashTable, int key, int * success) {
//     int hashIndex = hashing(key);
//     if (hashTable->items[hashIndex]->key == key) {
//         free(hashTable->items[hashIndex]);
//         insert(hashTable, key, NULL);
//         *success = SUCCESS;
//     }
// }

// testDelete
// First creates a testHash with the testing key/value pairs. Then creates an expectedHash with the provided expected key/value pairs.
// calls the helper function deleteItem on the testHash
// compares the updated testHash and expectedHash to see if the delete was successfull (or not) as expected
// if the key/value pair is deleted successfully and the hashes match a SUCCESS code 0 is returned
// if the value is not properly deleted then an ERROR -1 is returned
// int testDelete(HashTable * testHash, int key, int *expectedKeys, int *expectedValues) {    
//     HashTable * expectedHash = createHashTable(10);
//     bulkInsert(expectedHash, expectedKeys, expectedValues);
//     int success = ERROR;
//     deleteItem(testHash, key, &success);
//     if (success == SUCCESS && compare()) {
//         printf("The key %d was deleted successfully found as expected. \n", key);
//         return SUCCESS;
//     } 
//     printf("The key %d could not be deleted successfully as expected. \n", key);
//     return ERROR;
// }

// buildDeleteTests
// creates 5 test cases expected to pass the testDelete function
// creates 2 test cases (out of range) expected to fail the testDelete function
// to-do: will need a free testTable function to
// void buildDeleteTests() {
    


//     printf("Build Delete Test Passes: \n");
//     int testKeys1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
//     int testValues1[10] = { 0, 20, 30, 40, 50, 60, 70, 80 , 90, 100};
//     testDelete(1,testKeys1, testValues1);

//     int testKeys2[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
//     int testValues2[10] = {10, 20, 30, 40, 50, 60, 70, 0, 90, 100};
//     testDelete(8,testKeys2,testValues2);

//     int testKeys3[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
//     int testValues3[10] = {10, 0, 30, 40, 50, 60, 70, 80 , 90, 100};
//     testDelete(2,testKeys3, testValues3);

//     int testKeys4[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
//     int testValues4[10] = {10, 20, 30, 40, 0, 60, 70, 80 , 90, 100};
//     testDelete(5,testKeys4, testValues4);

//     int testKeys5[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
//     int testValues5[10] = {10, 20, 0, 40, 50, 60, 70, 80 , 90, 100};
//     testDelete(3,testKeys5, testValues5);

//     //5 Fail
//     printf("Build Delete Test Fails: \n");
//     int testKeys6[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
//     int testValues6[10] = {10, 20, 30, 40, 50, 60, 70, 80 , 90, 100};
//     testDelete(-10,testKeys6, testValues6);

//     int testKeys7[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
//     int testValues7[10] = {10, 20, 30, 40, 50, 60, 70, 80 , 90, 100};
//     testDelete(50,testKeys7, testValues7);
  
// }
//main calls buildSearchTests and buildDeleteTests in succession to begin the process of testing the search, reverse and delete functions
void main() {
   buildSearchTests();
//    buildDeleteTests();
}