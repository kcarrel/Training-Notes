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
    struct Node* left;
    struct Node* right;
} Node;

//Note: Per Sasha's feedback traverse function will accept a function pointer
// eX: so you can do traverse(tree, print_fn)
// traverse(tree, collect_fn)
void traverse() {

}

//To-do Note: may want to update addNode to take in a pointer to a Node for the later usage in other functions + to maintain ERROR/SUCCESS MESSAGE
//addNode:
//  Takes in a data value then creates a new node. If mem allocation does not fail then the node is assigned a value and left/right is set to NULL
//  returns 0 if successful, -1 if an error occurs and -2 if memory allocation failure occurs. 
void addNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node)); 
    if (node != NULL) {
        node->value = data;
        node->left = NULL; 
        node->right = NULL; 
        return SUCCESS;
    } else {
        return OVERFLOW;
    }
    return ERROR;
}

void buildTree() {

}

//main provides buildTree an array to insert in level order into a tree
void main() {
    int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
}