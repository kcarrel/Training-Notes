#include <stdio.h>
#include <stdlib.h>
// use macros to define alloc failure and return 
// #define ALLOC_NODE 

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
void traverse(Node * root) {
    if (root != NULL) {
        traverse(root->left);
        printf("%d \n", root->value);
        traverse(root->right);
    }
}

//To-do Note: may want to update addNode to take in a pointer to a Node for the later usage in other functions + to maintain ERROR/SUCCESS MESSAGE
//addNode:
//  Takes in a data value then creates a new node. If mem allocation does not fail then the node is assigned a value and left/right is set to NULL
//  returns 0 if successful, -1 if an error occurs and -2 if memory allocation failure occurs. 
Node * addNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node)); 
    if (node != NULL) {
        node->value = data;
        node->left = NULL; 
        node->right = NULL; 
        return node;
    } else {
        printf("Memory allocation has failed.");
    }
}

Node * smallestNode(Node * root) {
    Node * current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
//Three possibilities: Node is a leaf and easily removed from tree
//Node has only one child meaning that you just need to copy the child to the node then delete the child
// Node to be deleted has too children
Node * deleteNode(Node * root, int value) {
    if (root == NULL) {
        printf("Root node is empty.");
        return root;
    } 

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            Node * temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node * temp = root->left;
            free(root);
            return temp;
        }
        Node * temp = smallestNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp-> value);
    }
    return root;
}

// buildTree takes in an array of numbers, a root Node, integer and size of an array
// Builds a tree in-line order with the provided array of numbers
// Moved away from recursively implementing this function so as to allow for error messages 
Node * buildTree(int *arr, Node * root, int i, int n) {
    if (i < n) {
        Node * temp = addNode(arr[i]);
        root = temp;
        root->left = buildTree(arr, root->left, 2 * i + 1, n);
        root->right = buildTree(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

// newTree creates a new tree to run test cases against
// returns the root to the tree
Node * newTree() {
    int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node * root = (Node*)malloc(sizeof(Node)); 
    if (root != NULL) {
        root = buildTree(arr, root, 0, n);
        return root;
    } else {
        printf("An error has occurred.");
    }
}

// reverseTree takes in a root node  of a tree then recursively reverses the tree
Node * reverseTree(Node * root) {
    if (root == NULL) {
        return NULL;
    }
    Node * temp = root->left;
    root->left = reverseTree(root->right);
    root->right = reverseTree(temp);
    return root;
}
//functions:
//Delete Node
//Reverse Tree

//main provides buildTree an array to insert in level order into a tree
int main() {
    
   Node * root = newTree();
   traverse(root);

   reverseTree(root);
   traverse(root);
    
}