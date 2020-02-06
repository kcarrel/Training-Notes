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

void traverse() {

}

bool compare() {
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

//To-do: will need to think of how to handle collisions 
// buildHashTable receives an array of values
// loops through the values to create a key for the current value then inserts it into the existing hashTable.
// returns a SUCCESS code if all values are added into the hashTable successfully 
void buildHashTable(int *values) {
    int errcode = SUCCESS;
    for (int i = 0; i < SIZE; i++) {
        int success = ERROR;
        int key = hashing(values[i]);
        insert(key, values[i], success);
   }
   return errcode;
}

// To-dos:
// Insert a key
// testInsert
// buildInsertTests

//InsertTests
// 5 passes
// 5 Fails
// Empty Array
// Too large for hash table
// Collision


// Search
// testSearch
// buildSearchTests

// Delete a key
// testDelete
// buildDeleteTests


void main() {
   
}