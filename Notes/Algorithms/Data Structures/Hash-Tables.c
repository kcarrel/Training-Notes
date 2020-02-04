#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2
#define EMPTY -3

// Hash struct
typedef struct Item {
    int key;
    int value;
} Item;

typedef struct HashTable {
   int size;
   int count;
   Item** items;
} HashTable;


void print() {

}

void traverse() {

}

bool compare() {
    return true;
    return false;
}

Item * createItem(int key, int value, int success) {
    Item * item = malloc(sizeof(Item));
    if (item == NULL) return OVERFLOW;
    item->key = key;
    item->value = value;
    success = SUCCESS;
    return item;
}

HashTable * createHashTable(int size, int count, items) {
    HashTable * hashtable = malloc(sizeof(HashTable));
    if (hashtable == NULL) return OVERFLOW;
    hashtable->size = size;
    hashtable->count = 0;
    hashtable->items = calloc((size_t)hashtable->size, sizeof(Item *));
    return hashtable;
}

// To-dos:
// Insert a key
// testInsert
// buildInsertTests

// Search
// testSearch
// buildSearchTests

// Delete a key
// testDelete
// buildDeleteTests


void main() {
   
}