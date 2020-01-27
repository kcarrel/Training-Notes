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
int addRoot(Node * temp, int data) {
    if (temp != NULL) {
        temp->value = data;
        temp->left = NULL; 
        temp->right = NULL; 
        return SUCCESS;
    } else {
        return OVERFLOW;
    }
    return ERROR;
}

// buildTree takes in an array of numbers, a root Node, integer and size of an array
// reursively builds a tree in-line order with the provided array of numbers
// To-do: Add in error handling. Would prefer to still used recursion but not have to need to return the root node...
Node * buildTree(int *arr, Node * root, int i, int n) {
    if (i < n) {
        addRoot(root, arr[i]);
        root->left = buildTree(arr, root->left, 2 * i + 1, n);
        root->right = buildTree(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

//main provides buildTree an array to insert in level order into a tree
int main() {
    int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node * root = (Node*)malloc(sizeof(Node)); 
    if (root != NULL) {
        buildTree(arr, root, 0, n);
    } else {
        return OVERFLOW;
    }
    // traverse(root);
    return ERROR;
}