#include <stdio.h>
#include <stdlib.h>
// use macros to define alloc failure and return 
#define ALLOC_NODE 

#define SUCCESS 0
#define ERROR -1

//node struct
struct node {
    int value;
    struct node * next;
};



//createNode creates a node and makes it the next node to the provided head array
//Returns the new node if the memory allocation is successful
//Prints an error message if memory allocation fails 
struct node * createNextNode(int val) {
    struct node * temp = malloc(sizeof(*temp));
    if (temp != NULL) {
        temp->value = val;
        temp->next = NULL;
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

//appendNode adds a node to the end of linked list
//Returns 0 if add was successful, -1 if failure occurs
int appendNode(struct node* temp,struct node* last) {
    return SUCCESS;
}

//deleteNode

//Traverse LinkedList

// repetition of a complex allocation procedure:

//     checking for allocation errors
//     the whole thing can be a function

void buildList(){
    int result;
    struct node* head = (struct node*) malloc(sizeof(struct node)); 
    head->value = 0; 
    struct node* temp = head;  
    int i, testVals[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for (i = 0; i <= 10; i++) {
        struct node * last = createNextNode(testVals[i]);
        result = appendNode(temp, last);
        if (result == 0) {
            temp = last;
        }
    }
}

//Main first builds the testing singly linked list by calling the helper function buildList
void main() {
   buildList();


}