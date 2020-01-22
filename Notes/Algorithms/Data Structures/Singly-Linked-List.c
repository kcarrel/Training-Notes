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
// Exits when the node->next points to NULL (signifying end of linked list)
void traverse(Node* head) {
    Node* current_node = head;
   	while (current_node != NULL) {
        printf("%d \n", current_node->value);
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
            update = update->next;
            expect = expect->next;
        } else {
            printf("%d does not match %d. \n", update->value, expect->value);
            return ERROR;
        }
    }
    return SUCCESS;
}

//addNode creates a node and makes it the next node to the provided reference node
//Returns 0 if successful, -1 if an unknown error occurs, -2 if overflow occurs during memory allocation of space
int addNode(int val, Node* last, Node* next) {
    if (next != NULL) {
        next->value = val;
        next->next = NULL;
        last->next = next;
        return SUCCESS;
    } else {
        printf("Memory Allocation failure.");
        return OVERFLOW;
    }
    return ERROR;
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
    return ERROR;
}

//deleteNode: Takes in an index, traverse the linked list until finding the node in question, reassigns the previous node-> next to the current node's ->next 
//Returns 0 if successful, -1 if an unknown error occurs, -2 if overflow occurs during memory allocation of space
int deleteNode(Node * last, int index) {
    if (last == NULL) {
        return EMPTY;
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
    buildList(test, testVals, 10);
    deleteNode(test, index);
    buildList(expected, expectedVals, length);
    int result;
    result = compare(test, expected);
    if (result == 0) {
        printf("Woohoo it matches!");
        return SUCCESS;
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
    int testIndexOne = 10;
    int testOne[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90};
    testDelete(10, testOne, 10);

    int testIndexTwo = 8;
    int testTwo[9] = { 10, 20, 30, 40, 50, 60, 70, 90, 100};

    int testIndexThree = 3;
    int testThree[9] = { 10, 20, 40, 50, 60, 70, 80, 90, 100};

    int testIndexFour = 4;
    int testFour[9] = { 10, 20, 30, 50, 60, 70, 80, 90, 100};

    int testIndexFive = 9;
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

//reverseList takes in a pointer to a head Node then uses temporary nodes (previous/current/next) to copy and replace node values & node next appropriately 
//Returns 0 if successful, -1 if an unknown error occurs, -2 if overflow occurs during memory allocation of space
int reverseList(Node * head) 
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
    return SUCCESS;
} 

//reverseTest: takes in two linked lists
//  Runs test linked list through reverse function
//  Calls compare helper function to compare the updated test linked list with the expected linked list
//  Returns: If the comparison is equivalent returns a 0 for success. If not -1 for error. 
int reverseTest(Node * test, Node * expected) {
    int result;
    if (result == 0) {
        return SUCCESS;
    }
    return ERROR;
}

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

//Main uses buildList to create the Singly Linked List that is then passed to the helper functions addNode, deleteNode and reverseList for updates.
void main() {
    buildDeleteTests();

//     Node* head1 = malloc(sizeof(Node)); 
//     if (head1 == NULL) return OVERFLOW; 
//     head1->value = 0;
//     buildList(head1, testVals, 10);
//     // reverseList(head1);
//     traverse(head1);
}
