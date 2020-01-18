#include <stdio.h>
#include <stdlib.h>
// use macros to define alloc failure and return 
#define ALLOC_NODE 

#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2


//node struct
struct node {
    int value;
    struct node * next;
};

//Traverse: traverses a linked list and prints out the value of the current node, then sets the current node to the next node
// Exits when the node->next points to NULL
void traverse(struct node *head) {
    struct node *current_node = head;
   	while ( current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
}

//Compare: traverses a list of an "updated" linked list and an expected linked list & compares for matching values.
//Results: If values do not match then an error code is returned. If all values match then a success code is returned.
int compare(struct node * results, struct node * expected) {
    for (int i = 0; i < 10; i++) {
        struct node * result = results;
        struct node * expect = expected;
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
struct node * addNode(int val, struct node * last) {
    struct node * temp = malloc(sizeof(*temp));
    if (temp != NULL) {
        temp->value = val;
        temp->next = NULL;
        last->next = temp;
        return temp;
    } else {
        printf("Memory Allocation failure.");
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
    int testSix[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testSeven[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testEight[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testNine[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testTen[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
}

//Singly Linked List struct
typedef struct {
    struct node * head;
    struct node * tail;
    int length;
} SinglyLinkedList;

SinglyLinkedList * createLinkedList() {
    SinglyLinkedList * temp = calloc(1, sizeof(*temp));
    return temp;
}


//deleteNode: Takes in an index, traverse the linked list until finding the node in question, reassigns the previous node-> next to the current node's ->next 
//returns the head reference for the linked list
struct node * deleteNode(struct node * last, int index) {
    // if (last == NULL) {
    //     return EMPTY;
    // }
    struct node * temp = last;
    if (index == 0) {
        last = temp->next;
        free(temp);
    }
    //Find the node  before the one to be deleted and assign to temp
    for (int i = 0; temp != NULL && i < index - 1; i++) {
        temp = temp->next;
    } 
    struct node * newNext = temp->next->next;
    free(temp->next);
    temp->next = newNext;
    return last;
}


void buildDeleteTests() {
    //5 Pass 
    printf("Build Passes: \n");
    int testOne[9] = { 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testTwo[9] = { 10, 30, 40, 50, 60, 70, 80, 90, 100};

    int testThree[9] = { 10, 20, 40, 50, 60, 70, 80, 90, 100};

    int testFour[9] = { 10, 20, 30,  50, 60, 70, 80, 90, 100};

    int testFive[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 100};

    //5 Fail
    printf("Build Fails: \n");
    int testSix[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testSeven[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testEight[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testNine[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int testTen[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
}

struct node * reverseList(struct node * head) 
{ 
    struct node* prev = NULL; 
    struct node* current = head; 
    struct node* next = NULL; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    return prev;
} 
// repetition of a complex allocation procedure:

//     checking for allocation errors
//     the whole thing can be a function

//BuildList: Creates a head node then loops through an array of values which are provided to a addNode helper function to create a linked list
//Returns the head node for reference in main if the linked list is successfully created 
struct node * buildList(int *testVals, int length){ 
    struct node* head = (struct node*) malloc(sizeof(struct node)); 
    if (head != NULL) {
        head->value = 0; 
        struct node* last = head;  
        struct node * current;
        for (int i = 0; i < length; i++) {
            current = addNode(testVals[i], last);
            last = current;
        }
        return head;
    } else {
        printf("Memory allocation has failed.");
        // return OVERFLOW;
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
    struct node* head = buildList(testVals, 10);
    struct node* result = deleteNode(head, 2);
    traverse(result);

    struct node* head1 = buildList(testVals, 10);
    struct node* result1 = reverseList(head1);
    traverse(result1);
}