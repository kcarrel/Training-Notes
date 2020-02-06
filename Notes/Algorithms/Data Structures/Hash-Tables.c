#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2
#define EMPTY -3

#define SIZE 10

// Hash struct
typedef struct Item {
    int key;
    int value;
} Item;

Item * hashTable[SIZE];

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
void insert(int key, int value, int success) {
    hashTable[key] = createItem(key, value, success);
    if (hashTable[key]->value != value) {
        success = ERROR;
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
int buildHashTable(int *keys, int *values) {
    int errcode = SUCCESS;
    for (int i = 0; i < SIZE; i++) {
        int success = ERROR;
        int key = hashing(keys[i]);
        insert(key, values[i], success);
   }
   return errcode;
}

//to-do: Will need to think of a rescue in the case of a collision insertion
// searchHashTable takes in an integer key
// calls the helper function to hash the received key to correspond to an expected index within the hash table
// if the key at the position in the hashTable indicated by the hashing function matches the received key then return a SUCCESS code
// if a mistmatch occurs return an ERROR code
int searchHashTable(int key) {
    int hashIndex = hashing(key);
    if (hashTable[hashIndex]->key == key) {
        return SUCCESS;
    }
    return ERROR;
}

int testSearch(int key, int expectedOutcome) {

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