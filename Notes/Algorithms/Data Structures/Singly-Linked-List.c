#include <stdio.h>
#include <stdlib.h>
// use macros to define alloc failure and return 
#define ALLOC_NODE 

//node struct
struct node {
    int value;
    struct node * next;
};

//createNode creates a node 
//Returns the new node
struct node * createNode(int val, struct node * next) {
    struct node * temp = malloc(sizeof(*temp));
    if (temp != NULL) {
        temp->value = val;
        temp->next = next;
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



// repetition of a complex allocation procedure:

//     checking for allocation errors
//     the whole thing can be a function


void main() {


}