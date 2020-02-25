#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SUCCESS 0
#define ERROR -1
// Defined limit for a string key length 
#define LIMIT 10

// Hash Item struct
typedef struct Item {
    char* key;
    int value;
} Item;

// Hash Table struct
typedef struct HashTable {
    int size;
    Item** items;
} HashTable;


// returns true if a collision would happen for the initially hashed index for a key/value pair and false if no collision would occurred 
bool isCollision(HashTable * table, int index) {
    if (table->items[index] != NULL) {
        return true;
    }
    return false;
}

// equals checks the testHash and expectedHash for parity
// if the two HashTables match returns true
// if a mismatch occurs returns false
bool equals(HashTable * testHash, HashTable * expectedHash) {
    if (testHash->size != expectedHash->size ) {
        return false;
    }
    for (int i = 0; i < expectedHash->size; i++) {
        if (testHash->items[i] == NULL && expectedHash->items[i] == NULL) {
            continue; 
        } else if (testHash->items[i] != NULL && expectedHash->items[i] != NULL) {
            if (strcmp(testHash->items[i]->key, expectedHash->items[i]->key) != 0 || testHash->items[i]->value != expectedHash->items[i]->value) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}

// hashing 
// returns a "hashed" index based on modulus of the key's ASCII integer sum and the SIZE of the hashTable
// Explanation:  I used loselose because it was a simple hashing function that seemed adequate for the purposes of this exercise.
int hashing(HashTable *hashtable, char *key ) {
    int count = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        count += key[i];
    }
    return count % hashtable->size;
}


// creates a new Item struct
// returns new struct
Item * createItem(char key[], int value, int * success) {
    Item * item = malloc(sizeof(Item));
    if (item != NULL) {        
        item->key = strdup(key);
        item->value = value;
        *success = SUCCESS;
        return item;
    }
    return NULL;
}

// creates a new HashTable struct
// returns new HashTable struct
HashTable * createHashTable(int size) {
    if (size < 1) return NULL;
    HashTable * hashTable = malloc(sizeof(HashTable));
    if (hashTable == NULL) return NULL;
    hashTable->items = malloc(sizeof(Item) * size);
    if (hashTable->items == NULL) return NULL;
    hashTable->size = size;
    for (int i = 0; i < size; i++) {
        hashTable->items[i] = NULL;
    }
    return hashTable;
}

// insertion
// adds the new Item struct to the hashTable
// if the expected value is in the hashTable at the expected key then returns a success code
// if not, returns an error code
int insertion(HashTable * hashTable, int index, char key[], int value) {
    int success = ERROR;
    hashTable->items[index] = createItem(key, value, &success);     
    if (success != SUCCESS) {
        return ERROR;
    }
    return SUCCESS;
}

// Explicitly declare deleteItem and searchHashTable for insert and replace to use
int deleteItem(HashTable * hashTable, char key[], int value);
int searchHashTable(HashTable * hashTable, char key[], int value);

// replace
// returns SUCCESS if the key/value pair currently in the hashTable is replaced with the provided key/value pair
// returns ERROR if replacement is not made
int replace(HashTable * hashTable, char key[], int value) {
    int hashIndex = hashing(hashTable,key);
    for (int i = 0; i < hashTable->size; i++) {
        int index = (hashIndex + i) % hashTable->size;
        if (hashTable->items[index] != NULL && strcmp(hashTable->items[index]->key, key) == 0) {
            deleteItem(hashTable, hashTable->items[hashIndex]->key, hashTable->items[hashIndex]->value);
            return insertion(hashTable, index, key, value);
        }
    }
    return ERROR;
}
// insert 
// adds the new Item struct to the hashTable using a helper function called insertion
// if the expected value is in the hashTable at the expected key then returns a success code
int insert(HashTable * hashTable, char key[], int value) {
    int hashIndex = hashing(hashTable, key);
    //Must replace it already exists!
    if (isCollision(hashTable, hashIndex)) {
        if (strcmp(hashTable->items[hashIndex]->key, key) == 0) {  
            deleteItem(hashTable, hashTable->items[hashIndex]->key, hashTable->items[hashIndex]->value);
            return insertion(hashTable, hashIndex, key, value);
        } else if (searchHashTable(hashTable, key, value) == SUCCESS) {
            return replace(hashTable, key, value);
        }
        //check second half of hashTable
        for (int i = 0; i < hashTable->size; i++) {
            int index = (hashIndex + i) % hashTable->size;
            if (isCollision(hashTable, index)) {
                index++; 
                index % hashTable->size;  
            } else {
                return insertion(hashTable, index, key, value);
            }
        }
        //check the first half of the hashTable before the initially hashedIndex
        for (int i = 0; i < hashIndex; i++) {
            if (isCollision(hashTable, i) == false) {
                return insertion(hashTable, i, key, value);
            }
        }
        return ERROR;
    }
    return insertion(hashTable, hashIndex, key, value);
}

// bulkInsert 
// returns a SUCCESS code if all values are added into the hashTable successfully 
// returns an ERROR code if a value cannot be added into the hashTable 
int bulkInsert(HashTable * hashTable, char keys[][10], int keyCount, int* values, int valuesCount) {
    if (keyCount != valuesCount) {
        printf("ERROR: The number of keys provided does not match the number of value pairs provided. \n");
        return ERROR;
    } else if (keyCount > hashTable->size) {
        printf("ERROR: The number of key/value pairs provided exceeds the amount allowed to be inserted in the hashTable. \n");
        return ERROR;
    }
    int success;
    for (int i = 0; i < hashTable->size; i++) {
        success = insert(hashTable , keys[i], values[i]);
        if (success == ERROR) {
            return ERROR;
        }
    }
   return SUCCESS;
}

// createTestHashTable
// returns a HashTable struct to use for testing 
HashTable * createTestHashTable() {
    char keys[10][10] = { "KeyOne", "KeyTwo", "KeyThree", "KeyFour", "KeyFive", "KeySix", "KeySeven", "KeyEight", "KeyNine", "KeyTen"};
    int value[10]= { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    HashTable * testHash = createHashTable(10);
    bulkInsert(testHash, keys, 10, value, 10);
    return testHash;
}

// testInsertCollision
// prints an ERROR message and returns ERROR if key value pairs cannot be inserted into hashTable or if key value pairs at specified indexes do not match expectations
// prints a SUCCESS message and returns SUCCESS if key value pairs are inserted correctly at the expected indexes after resolving a hashing collision
int testInsertCollision(HashTable * hashTable, char keyOne[], int valueOne, char keyTwo[], int valueTwo) {
    int index1 = hashing(hashTable, keyOne);
    int index2 = (index1 + 1) % hashTable->size;
    int success1 = insert(hashTable, keyOne, valueOne);
    int success2 = insert(hashTable, keyTwo, valueTwo);
    if (success1 != SUCCESS || success2 != SUCCESS) {
        printf("Key value pairs were not inserted in the hashTable. \n");
        return ERROR;
    }
    if (hashTable->items[index1] == NULL || hashTable->items[index2] == NULL) {
        printf("The key value pairs were not inserted at the expected indexes. \n");
        return ERROR;
    }
    //Only checking values instead of both values and keys as a value wouldn't be inserted without the expected key pair and for relative simplicity
    if (hashTable->items[index1]->value == valueOne && hashTable->items[index2]->value == valueTwo) {
        printf("The key value pairs are in the hashTable at the expected indexes after resolving a hashing collision. \n");
        return SUCCESS;
    } else {
        printf("The key value pairs were not inserted at the expected indexes. \n");
        return ERROR;
    }
}


// testInsertCapcity
// prints an error message and returns ERROR if insert is unsuccessful due to hashTable being at capcity
// returns SUCCESS if all key/value pairs can be inserted into the hashTable
int testInsertCapacity() {
    HashTable * testHash = createHashTable(10);
    char keys[11][10] = {
        "KeyOne", "KeyTwo", "KeyThree", "KeyFour", "KeyFive", "KeySix", "KeySeven", "KeyEight", "KeyNine", "KeyTen",
        "KeyEleven", 
    };
    int values[11] = {
         10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
         11
    };
    int success = SUCCESS;
    for (int i = 0; i < 100; i++) {
        success = insert(testHash, keys[i], values[i]);
        if (success != SUCCESS) {
            printf("ERROR! HashTable is at capacity! No more values can be added. \n");
            return SUCCESS;
        }
    }
    return ERROR;

}

int testDuplicateInsert (char keyOne[], int valueOne, char keyTwo[], int valueTwo) {
    HashTable * testHash = createHashTable(10);
    int index1 = hashing(testHash, keyOne);
    int index2 = hashing(testHash, keyTwo);
    int success1 = insert(testHash, keyOne, valueOne);
    int success2 = insert(testHash, keyTwo, valueTwo);
    if (success1 != SUCCESS || success2 != SUCCESS) {
        printf("Key value pairs were not inserted in the hashTable. \n");
        return ERROR;
    }
    if (testHash->items[index1] == NULL || testHash->items[index2] == NULL) {
        printf("The key value pairs were not inserted at the expected indexes. \n");
        return ERROR;
    }
    if (testHash->items[index1]->value == valueTwo) {
        printf("The second key value pair replaced the first duplicate value in the hashTable which is the expected behavior. \n");
        return SUCCESS;
    } else {
        printf("The second key value pair did not replace the first duplicate value in the hashTable which is unexpected behavior. \n");
        return ERROR;
    }
}
// buildInsertTests
// creates a test for the case of collisions
// createas a test for the case of hashTable capcity being reached
void buildInsertTests() {
   //build an empty hashTable to test insert/collision on
    HashTable * testHash = createHashTable(10);
    printf("Build Insert Collision Test: \n");

   // Brute Forced a Collision (Same Key = Same hashingIndex)
   // Expect that the second KeyOne will have an index = hashing(KeyOne) + 1 % hashTable->size
    testInsertCollision(testHash, "KeyFive", 10, "KeyNine", 20);
    
    printf("Build Insert Capacity Test: \n");
    //Test how Insert handles being sent # of values that exceeds hashTable capabilities
    testInsertCapacity();

    printf("Build Insert Duplicate Key Test: \n");
    //Test how Insert handles being sent a duplicate key
    testDuplicateInsert("KeyOne", 10, "KeyOne", 20);
}

// searchHashTable
// if the key/value pair is found through linear probing then return a SUCCESS code
// if key/value pair is not found return an ERROR code
int searchHashTable(HashTable * hashTable, char key[], int value) {
    int hashIndex = hashing(hashTable,key);
    for (int i = 0; i < hashTable->size; i++) {
        int index = (hashIndex + i) % hashTable->size;
        if (hashTable->items[index] != NULL && hashTable->items[index]->value == value && strcmp(hashTable->items[index]->key, key) == 0) {
            return SUCCESS;
        }
    }
    return ERROR;
}


// testSearch
// if the key/value pair is found successfully and the expectedOutcome matches a SUCCESS code 0 is returned then a success message is printed and a SUCCESS code is returned
// if the value is not found then a failure message is printed and an ERROR -1 is returned
// if the outcome does not match what is expected a mismatch message is printed and an ERROr -1 is returned 
int testSearch(char key[], int value, int expectedOutcome) {
    size_t len = strlen(key);
    if (len > LIMIT) {
        printf("ERROR: The key provided has a character count over the limit allowed within the hashTable. \n");
        return ERROR;
    } else if (key[0] == '\0') {
        printf("ERROR: The key provided is an empty string and cannot be found in the hashTable. \n");
        return ERROR;
    }
    HashTable * testHash = createTestHashTable();
    int success = searchHashTable(testHash, key, value);
    if (success == SUCCESS && expectedOutcome == SUCCESS) {
        printf("The key/value pair: %s and %d was successfully found as expected. \n", key, value);
        return SUCCESS;
    } else if (success == ERROR && expectedOutcome == ERROR) {
        printf("The key/value pair: %s and %d was not found as expected. \n", key, value);
        return SUCCESS;
    }
    printf("ERROR: The key/value pair: %s and %d could not be found in the hashTable which does not match expectations. \n", key, value);
    return ERROR;
}

// buildSearchTests
// creates 5 test cases expected to pass the testSearch function
// creates 5 test cases (out of range) expected to fail the testSearch function
void buildSearchTests() {
    printf("Build Search Test Passes: \n");
    testSearch("KeyTwo", 20, SUCCESS);
    testSearch("KeyEight", 80, SUCCESS);
    testSearch("KeyThree", 30, SUCCESS);
    testSearch("KeyFour", 40, SUCCESS);
    testSearch("KeyNine", 90, SUCCESS);

    //5 Fail
    printf("Build Search Test Fails: \n");
    testSearch("KeyNinety", 0, ERROR);
    testSearch("LaLa", 10, ERROR);
    testSearch("Error", 20, ERROR);
    testSearch("", 30, ERROR);
    testSearch("VERYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYLONNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNG", 40, ERROR);
}
 
// deleteItem
// if key/value pair is successfully deleted return SUCCESS code
// if key/value pair cannot be deleted return ERROR code 
int deleteItem(HashTable * hashTable, char key[], int value) {
    int hashIndex = hashing(hashTable, key);
    for (int i = 0; i < hashTable->size; i++) {
        int index = (hashIndex + i) % hashTable->size;
        if (hashTable->items[index] != NULL && hashTable->items[index]->value == value && strcmp(hashTable->items[index]->key, key) == 0) {
            free(hashTable->items[index]->key);
            free(hashTable->items[index]);
            return SUCCESS;
        } 
    }
    return ERROR;
}

// testDelete
// if the key/value pair is deleted successfully, the key/value pair cannot be found in the testHash and the expectation is that this deletion is successfull a SUCCESS code 0 is returned and corresponding message printed
// if the key/value pair is not deleted successfully, the key/value pair cannot be found in the testHash and the expectation is that this deletion fails an ERROR code -1 is returned and corresponding message printed
int testDelete(char key[], int value, int expectedOutcome) {  
    HashTable * testHash = createTestHashTable();  
    int deleteSuccess = deleteItem(testHash, key, value);
    int searchSuccess = searchHashTable(testHash, key, value);
    if (deleteSuccess == SUCCESS && searchSuccess == ERROR && expectedOutcome == SUCCESS) {
        printf("The key/value pair: %s and %d was deleted successfully as expected. \n", key, value);
        return SUCCESS;
    }  else if (deleteSuccess == ERROR && searchSuccess == ERROR && expectedOutcome == ERROR) {
        printf("The key/value pair: %s and %d could not be deleted successfully as expected. \n", key, value);
        return ERROR;
    } 
    printf("ERROR: The key/value pair: %s and %d could not be deleted in the hashTable which does not match expectations. \n", key, value);
    return ERROR;
}

// buildDeleteTests
// creates 4 test cases expected to pass the testDelete function
// creates 2 test cases (out of range) expected to fail the testDelete function
void buildDeleteTests() {
    printf("Build Delete Test Passes: \n");
    testDelete("KeyOne", 10, SUCCESS);
    testDelete("KeyTwo", 20, SUCCESS);
    testDelete("KeyEight", 80, SUCCESS);
    testDelete("KeyTen", 100, SUCCESS);


    printf("Build Delete Test Fails: \n");
    // neither key nor value present
    testDelete("Keyyyyyyy", 0, ERROR);
    // key present value not
    testDelete("KeyOne", 100, ERROR);
    // key not present value present
    testDelete("KeyZero", 100, ERROR);
}

int equalsEmpty(){
    printf("Build Equals Empty Test: \n");
    HashTable * testHash = createTestHashTable();
    HashTable * expectedHash = createTestHashTable();
    if (equals(testHash, expectedHash)) {
        printf("The two empty hashTables are equivalent which is the expected outcome! \n");
        return SUCCESS;
    } else {
        printf("The two empty hashTables are not equivalent which is not the expected outcome.  \n");
        return ERROR;
    }
}
 
 
 //main calls buildSearchTests, buildDeleteTests, buildInsertTests and equalsEmpty in succession to begin the process of testing the search, delete and insert functions
void main() {    
   buildSearchTests();
   buildDeleteTests();
   buildInsertTests();
   equalsEmpty();
}