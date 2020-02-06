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

Item* testHash[SIZE];
Item* expectedHash[SIZE];

void print() {

}

void traverse(Item * item) {
    int value = item->value;
    int key = item->key;
    for (int i = 0; i < SIZE; i++) {
        printf("Key: %d Value: %d \n", key, value);
    }
}

bool compare(Item * hashTable, Item * expected) {
    return true;
    return false;
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
        int success = ERROR;
        int key = hashing(keys[i]);
        insert(type, key, values[i], success);
   }
   return errcode;
}

//to-do: Will need to think of a rescue in the case of a collision insertion
// searchHashTable takes in an integer key
// calls the helper function to hash the received key to correspond to an expected index within the hash table
// if the key at the position in the test hashTable indicated by the hashing function matches the received key then return a SUCCESS code
// if a mistmatch occurs return an ERROR code
int searchHashTable(int type, int key, int * success) {
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
    testSearch(10, SUCCESS);
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

int deleteItem() {
    return SUCCESS; 
    return ERROR;
}


//To-do: Like above need to make adjustments based on potential insertion collisions messing up the hashing function
// Also saw an alternative way to do delete is just to set the key to -1?
// testDelete takes in an Item struct
// finds the key of the provided Item then passes it to the helper function to hash it and find the corresponding index
// if the key at the position in the hashTable indicated by the hashing function matches the received key then sets an empty delete Item equal to the Item at the hashIndex
// if a failure occurs return an ERROR code
int testDelete(Item * item) {
    int key = item->key;
    int hashIndex = hashing(key);
    if (hashTable[hashIndex]->key == key) {
        Item * deleteItem;
        hashTable[hashIndex] = deleteItem;
        return SUCCESS;
    }  
    return ERROR;
}

void buildDeleteTests() {

}

void main() {
   
}