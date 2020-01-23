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
    struct Node* prev;
} Node;

//Traverse: traverses a linked list and prints out the value of the current node, then sets the current node to the next node
// Exits when the node->next points to NULL
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
void addNode(int val, Node* last, Node* next) {
    Node* temp = last; 
  
    next->value = val; 
    next->next = NULL; 

    if (temp == NULL) { 
        next->prev = NULL; 
        temp = next; 
        return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (temp->next != NULL) {
        temp = temp->next; 
    }
    temp->next = next; 
    next->prev = temp; 
    return; 
}

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

void main() {
    int testVals[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    Node* head = malloc(sizeof(Node)); 
    head->value = 0;
    head->prev = NULL;
    buildList(head, testVals, 10);
    traverse(head);
    

    // Node* head1 = buildList(testVals, 10);
    // Node* result1 = reverseList(head1);
    // traverse(result1);
}