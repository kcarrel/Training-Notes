#include <stdio.h>    
#include <stdlib.h>
// use macros to define alloc failure and return 
#define ALLOC_NODE 

#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2
#define EMPTY -3

#define LIMIT 15


//node struct
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

//Traverse: traverses a linked list and prints out the value of the current node, then sets the current node to the next node
// Exits when the node->next points to NULL (signifying end of linked list)
void traverse(Node* head) {
    Node* current_node = head;
    Node* next = head->next;
    Node* prev = head->prev;
   	while (current_node != NULL) {
        printf("Current Value: %d \n", current_node->value);    
        current_node = current_node->next;
    }
}

//Compare: traverses a list of an "updated" linked list and an expected linked list & compares for matching values.
//Results: If values do not match then an error code is returned. If all values match then a success code is returned.
int compare(Node * updated, Node * expected) {
    for (int i = 0; i < 10; i++) {
        Node * update = updated;
        Node * expect = expected;
        if (update->value == expect->value) {
            if (update->next == expect->next) {
                if (update->prev == expect->prev) {
                    update = update->next;
                    expect = expect->next;
                }
            }
        } else {
            printf("%d does not match %d. \n", update->value, expect->value);
            return ERROR;
        }
    }
    printf("Both Linked Lists provided match! \n");
    return SUCCESS;
}

//addNode creates a node and makes it the next node to the provided reference node
//Returns 0 if successful, -1 if an unknown error occurs, -2 if overflow occurs during memory allocation of space
void addNode(int val, Node* last, Node* next) {
    Node* temp = last; 
  
    next->value = val; 
    next->next = NULL; 

    if (temp == NULL) { 
        next->prev = NULL; 
        temp = next; 
        return; 
    } 
  
    while (temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = next; 
    next->prev = temp; 
    return; 
}

//buildList takes in a head node, an array of testing values and an array length
//loops through the test values to call on the helper function addNode in order to build a Linked List
//Returns 0 if successful, -1 if an unknown error occurs, -2 if overflow occurs during memory allocation of space
int buildList(Node * head, int *testVals, int length){ 
    if (head != NULL) {
        Node* last = malloc(sizeof(Node)); 
        for (int i = 0; i < length; i++) {
            Node* next = malloc(sizeof(Node)); 
            if (i == 0) {
                addNode(testVals[i], head, next);
                last = next;

            } else {
                addNode(testVals[i], last, next);
                last = next;
            }
        }
        return SUCCESS;
    } else {
        printf("Memory allocation has failed.");
        return OVERFLOW;
    }
}

//deleteNode: Takes in an index, traverse the linked list until finding the node in question, reassigns the previous node-> next to the current node's ->next 
//Returns 0 if successful, -1 if an unknown error occurs, -2 if overflow occurs during memory allocation of space
int deleteNode(Node * last, int index) {
    if (last == NULL) return EMPTY;
      if (index > LIMIT || index < 0) {
        printf("This index is too darn large! \n");
        return ERROR;
    }
    
    Node* temp = malloc(sizeof(Node)); 
    if (temp != NULL) {
        temp = last;
    } else {
        return OVERFLOW;
    }
    if (index == 0) {
        last = temp->next;
        free(temp);
    }
    //Find the node  before the one to be deleted and assign to temp
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    } 
    Node * newNext = temp->next->next;
    free(temp->next);
    temp->next = newNext;
    return SUCCESS;
}

//testDelete:
//  Takes in two linked lists and an int index
//  Runs test linked list through delete function
//  Compares the updated test linked list with the expected linked list using compare helper function
//  If the comparison is equivalent returns a 0 for success. If not -1 for error. 

//toDo: make this do 1 thing
int testDelete(int index, int *expectedVals, int length) {
    int testVals[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    Node* test = malloc(sizeof(Node));
    Node* expected = malloc(sizeof(Node));
    if (test == NULL || expected == NULL) return OVERFLOW; 
    test->value = 0;
    test->prev = NULL;
    buildList(test, testVals, 10);
    int success;
    success = deleteNode(test, index);
    if (success == 0) {
        buildList(expected, expectedVals, length);
        int result;
        result = compare(test, expected);
        if (result == 0) {
            return SUCCESS;
        }
    }
    return ERROR;
}

//buildDeleteTests;
//  takes in a Node test, calls on the helper function buildList to create a test linked list with the provided testing values
//  calls helper function delete to update the test linked list by deleting the node at the provided test index
//toDo: make this do 1 thing

void buildDeleteTests() {
    //5 Pass 
    printf("Build Passes: \n");
    int testOne[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90};
    testDelete(10, testOne, 9);

    int testTwo[9] = { 10, 20, 30, 40, 50, 60, 70, 90, 100};
    testDelete(8, testTwo, 9);

    int testThree[9] = { 10, 20, 40, 50, 60, 70, 80, 90, 100};
    testDelete(3, testThree, 9);

    int testFour[9] = { 10, 20, 30, 50, 60, 70, 80, 90, 100};
    testDelete(4, testFour, 9);

    int testFive[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 100};
    testDelete(9, testFive, 9);

    //5 Fail
    printf("Build Fails: \n");
    //Empty Input
    int testSix[0] = {};
    testDelete(9, testSix, 0);

    //Input too large
    int testSeven[100] = { 
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    };
    testDelete(9, testSeven, 100);

    int testEight[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    testDelete(2, testEight, 10);

    int testNine[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    testDelete(20, testNine, 10);

    int testTen[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    testDelete(-20, testTen, 10);
}

//reverseList takes in a pointer to a head Node then uses temporary nodes (previous/current/next) to copy and replace node values & node next appropriately 
//Returns 0 if successful, -1 if an unknown error occurs, -2 if overflow occurs during memory allocation of space
int reverseList(Node * head, Node * expected) 
{ 
    if (head == NULL || head->next == NULL) {
        return EMPTY;
    }
    Node* prev = NULL; 
    Node* current = head; 
    Node* next = NULL; 

    while (current != NULL) { 
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } 
    head = prev; 
    compare(head, expected);
    return SUCCESS;
} 

//testReverse: takes in two linked lists
//  Runs test linked list through reverse function
//  Calls compare helper function to compare the updated test linked list with the expected linked list
//  Returns: If the comparison is equivalent returns a 0 for success. If not -1 for error. 

int testReverse(int *expectedVals, int expectedHead) {
    int testVals[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    Node* test = malloc(sizeof(Node));
    Node* expected = malloc(sizeof(Node));
    if (test == NULL || expected == NULL) return OVERFLOW; 
    test->value = 0;
    expected->value = expectedHead;
    buildList(test, testVals, 10);
    int success;
    success = reverseList(test, expected);
    if (success == 0) {
            return SUCCESS;
    }
    return ERROR;
}

void buildReverseTests() {
    //5 Pass 
    printf("Build Passes: \n");
    int resultOne[10] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    testReverse(resultOne, 100);

    int resultTwo[10] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    testReverse(resultTwo, 100);

    int resultThree[10] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    testReverse(resultThree, 100);

    int resultFour[10] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    testReverse(resultFour, 100);

    int resultFive[10] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    testReverse(resultFive, 100);

    //5 Fail
    printf("Build Fails: \n");
    //Empty List
    int resultSix[0] = {};
    testReverse(resultSix, -7);

    //Input too large
    int resultSeven[100] = { 
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
        10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    };
    testReverse(resultSeven, 10);

    int resultEight[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    testReverse(resultEight, 0);

    int resultNine[10] = { -120, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    testReverse(resultNine, -6);

    int resultTen[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    testReverse(resultTen, 2);

}

//Main uses buildList to create the Singly Linked List that is then passed to the helper functions addNode, deleteNode and reverseList for updates.
void main() {
    buildDeleteTests();
    buildReverseTests();
}
