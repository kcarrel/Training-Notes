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
//returns
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

// repetition of a complex allocation procedure:

//     checking for allocation errors
//     the whole thing can be a function

//BuildList:
//Returns 0 if list is successfully built, -1 if an error occurs and -2 if a memory allocation failure occurs
struct node * buildList(){ 
    struct node* head = (struct node*) malloc(sizeof(struct node)); 
    if (head != NULL) {
        head->value = 0; 
        struct node* last = head;  
        struct node * current;
        int i, testVals[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
        for (i = 0; i < 10; i++) {
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
void main() {
    struct node* head = buildList();
    struct node* result = deleteNode(head, 2);
    traverse(result);
}