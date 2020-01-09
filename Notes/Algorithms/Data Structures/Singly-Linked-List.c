#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};



void insert() {

}

void print(struct Node* head) {
    struct Node* temp = head; 
    while (temp != NULL) { 
        printf("%d  ", temp->value);
        temp = temp->next; 
    } 
}

void main() {
    struct Node* head = NULL;
    struct Node* middle = NULL;
    struct Node* tail = NULL;

    head = (struct Node*)malloc(sizeof(struct Node)); 
    middle = (struct Node*)malloc(sizeof(struct Node)); 
    tail = (struct Node*)malloc(sizeof(struct Node)); 

    head -> value = 10;
    head -> next = middle;

    middle -> value = 20;
    middle -> next = tail;

    tail -> value = 30;
    tail -> next = NULL;
    
    print(head);
}