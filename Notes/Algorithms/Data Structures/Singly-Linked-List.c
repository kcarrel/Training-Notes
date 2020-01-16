#include <stdio.h>
#include <stdlib.h>

//node struct
struct node {
    int value;
    struct node * next;
};

//createNode creates a node 
//Returns the new node
struct node * createNode(int val, struct node * next) {
    struct node * temp = malloc(sizeof(*temp));
    temp->value = val;
    temp->next = next;
    return temp;
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

void main() {


}