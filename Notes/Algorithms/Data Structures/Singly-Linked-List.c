#include <stdio.h>
#include <stdlib.h>
// use macros to define alloc failure and return 
#define ALLOC_NODE 

#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2
#define EMPTY -3


//node struct
typedef struct Node {
    int value;
    struct Node* next;
} Node;

//Traverse: traverses a linked list and prints out the value of the current node, then sets the current node to the next node
// Exits when the node->next points to NULL
void traverse(Node* head) {
    Node* current_node = head;
   	while (current_node != NULL) {
        printf("%d \n", current_node->value);
        current_node = current_node->next;
    }
}

//Compare: traverses a list of an "updated" linked list and an expected linked list & compares for matching values.
//Results: If values do not match then an error code is returned. If all values match then a success code is returned.
int compare(Node * results, Node * expected) {
    for (int i = 0; i < 10; i++) {
        Node * result = results;
        Node * expect = expected;
        if (result->value == expect->value) {
            result = results->next;
            expect = expect->next;
        } else {
            printf("%d does not match %d.", result->value, expect->value);
            return ERROR;
        }
    }
    return SUCCESS;
}

//addNode creates a node and makes it the next node to the provided reference node
//Returns the new node if the memory allocation is successful
//Prints an error message if memory allocation fails 
int addNode(int val, Node* last, Node* next) {

    if (next != NULL) {
        next->value = val;
        next->next = NULL;
        last->next = next;
        // printf("%d \n", next->value);
        return SUCCESS;
    } else {
        printf("Memory Allocation failure.");
        return OVERFLOW;
    }
}


void buildAddTests() {
    //5 Pass 
    printf("Build Passes: \n");
    int testOne[11] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 82, 100};

    int testTwo[11] = { 10, 20, 30, 40, 50, 60, 60, 70, 80, 90, 100};

    int testThree[11] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 200};

    int testFour[11] = { 10, 20, 44, 30, 40, 50, 60, 70, 80, 90, 100};

    int testFive[11] = { 10, 20, 30, 40, 29, 50, 60, 70, 80, 90, 100};

    //5 Fail
    printf("Build Fails: \n");
    //Empty Test
    int testSix[0] = {};

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

    int testEight[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testNine[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testTen[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
}

//deleteNode: Takes in an index, traverse the linked list until finding the node in question, reassigns the previous node-> next to the current node's ->next 
//returns the head reference for the linked list
int deleteNode(Node * last, int index) {
    if (last == NULL) {
        return EMPTY;
    }
    Node* temp = malloc(sizeof(Node)); 
    temp = last;
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
}

//Test cases for the delete function
void buildDeleteTests() {
    //5 Pass 
    printf("Build Passes: \n");
    int testOne[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90};

    int testTwo[9] = { 10, 20, 30, 40, 50, 60, 70, 90, 100};

    int testThree[9] = { 10, 20, 40, 50, 60, 70, 90, 100};

    int testFour[9] = { 10, 20, 30,  50, 60, 70, 80, 90, 100};

    int testFive[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 100};

    //5 Fail
    printf("Build Fails: \n");
    //Empty Input
    int testSix[0] = {};

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

    int testEight[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testNine[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testTen[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
}

int reverseList(Node * head) 
{ 
    Node* prev = NULL; 
    Node* current = head; 
    Node* next = NULL; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    return SUCCESS;
} 

//To-Do: Aren't there too many interesting test cases for a successful reverse?
void buildReverseTests() {
    //5 Pass 
    printf("Build Passes: \n");
    int testOne[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int resultOne[11] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};

    int testTwo[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int resultTwo[11] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};

    int testThree[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int resultThree[11] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};

    int testFour[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int resultFour[11] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};

    int testFive[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int resultFive[11] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};

    //5 Fail
    printf("Build Fails: \n");
    //Empty List
    int testSix[0] = {};

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

    int testEight[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testNine[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testTen[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
}

// repetition of a complex allocation procedure:

//     checking for allocation errors
//     the whole thing can be a function

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

//Main first builds the testing singly linked list by calling the helper function buildList
//To-do: Work in error codes while still returning references to the nodes being updated?
// Functions:
//Add
//Delete
//Traverse
//Reverse LL
void main() {
    int testVals[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    Node* head = malloc(sizeof(Node)); 
    head->value = 0;
    buildList(head, testVals, 10);

    deleteNode(head, 2);
    traverse(head);



    // Node* head1 = buildList(testVals, 10);
    // Node* result1 = reverseList(head1);
    // traverse(result1);
}
