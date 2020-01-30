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
    return ;
}

//Compare: traverses a list of an "updated" linked list and an expected linked list & compares for matching values.
//Results: If values do not match then an error code is returned. If all values match then a success code is returned.
int compare(Node * updated, Node * expected) {
    if (updated == NULL && expected == NULL) return EMPTY;
    if (updated != NULL && expected != NULL) {
        return (
            updated->value == expected->value && 
            compare(updated->left, expected->left) && 
            compare(updated->right, expected->right) 
        );
    }
    return ERROR;
}

//  addNode:
//  Takes in a data value then creates a new node. If mem allocation does not fail then the node is assigned a value and left/right is set to NULL
//  Checks to see if the root Node provided is the root parent of the tree - if so sets value to data provided then left/right to NULL
//  If it is a leaf to add to the tree checks to see which branch the value belongs to remain sorted
//  returns root Node 
Node * addNode(Node * root, int data) {
    if (root == NULL) {
        root = (Node*)malloc(sizeof(Node)); 
        if (root != NULL) {
            root->value = data;
            root->left = NULL; 
            root->right = NULL;
        } 
    } else if (data < root->value) {
        root->left = addNode(root->left, data);
    } else if (data > root->value) {
        root->right = addNode(root->right, data);
    }
    return root;
}

// newTree creates a new tree to run test cases against
// returns the root to the tree
Node * newTree(int *arr, int length) {
    Node * root;
    root = NULL;
    for (int i = 0; i < length; i++) {
        root = addNode(root, arr[i]);
    }
    return root;
}

// finds the smallestNode and returns the node
Node * smallestNode(Node * root) {
    if (root == NULL) {
        return root;
    } else if(root->left == NULL) {
        return root;
    } else {
        return smallestNode(root->left);
    }  
}

// finds the largestNode and returns the node
Node * largestNode(Node * root) {
    if (root == NULL) {
        return root;
    } else if(root->right == NULL) {
        return root;
    } else {
        return largestNode(root->left);
    }  
}

// deleteNode takes in a root node and a value to delete
// if/else figures out which branch the node would be based on value
// returns root of updated tree
Node * deleteNode(Node * root, int value) {
    if (root == NULL) {
        printf("Root node is empty.");
        return root;
    } 

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else if (root->left && root->right){
        Node * temp = smallestNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, root->value);
    } else {
        Node * temp = root;
        if (root->left == NULL) {
            root = root->right;
        } else if (root->right == NULL) {
            root = root->left;
        }
        free(temp);
    }
    return root;
}

//testDelete
int testDelete(int value, int *expectedVals, int length) {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node * test = newTree(arr, n);
    Node* expected = malloc(sizeof(Node));
    if (test == NULL || expected == NULL) return OVERFLOW; 
    deleteNode(test, value);
    int result;
    result = compare(test, expected);
    if (result == 0) {
        return SUCCESS;
    }
    return ERROR;
}

void buildDeleteTests() {
    //5 Pass 
    printf("Build Delete Test Passes: \n");
    int testOne[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
    testDelete(10, testOne, 9);

    int testTwo[9] = { 1, 2, 3, 4, 5, 6, 7, 9, 10 }; 
    testDelete(8, testTwo, 9);

    int testThree[9] = { 1, 2, 4, 5, 6, 7, 8, 9, 10 }; 
    testDelete(3, testThree, 9);

    int testFour[9] = { 1, 2, 3, 5, 6, 7, 8, 9, 10 }; 
    testDelete(4, testFour, 9);

    int testFive[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 10 }; 
    testDelete(9, testFive, 9);

    //5 Fail
    printf("Build Delete Test Fails: \n");
    //Empty Input
    int testSix[0] = {};
    testDelete(9, testSix, 0);

    //Input too large
    int testSeven[100] = { 
        1, 2, 3, 4, 5, 6, 7, 8, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    };
    testDelete(9, testSeven, 100);

    int testEight[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testDelete(11, testEight, 10);

    int testNine[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testDelete(20, testNine, 10);

    int testTen[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testDelete(-20, testTen, 10);
}

// searchNode takes in a root node and a value to find
// if/else figures out which branch the node would be in based on value
// returns 0 if value is successfully found 
Node * searchNode(Node * root, int value) {
    if (root == NULL) {
        printf("Root node is empty.");
        return root;
    } 
    if (value < root->value) {
        root->left = searchNode(root->left, value);
    } else if (value > root->value) {
        root->right = searchNode(root->right, value);
    } else if (root->left && root->right){
        Node * temp = smallestNode(root->right);
        root->value = temp->value;
        root->right = searchNode(root->right, root->value);
    } else {
        return 0;
    }
    return root;
}

int testSearch(int value, int *expectedVals, int length) {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node * test = newTree(arr, n);
    Node* expected = malloc(sizeof(Node));
    if (test == NULL || expected == NULL) return OVERFLOW; 
    searchNode(test, value);
    int result;
    result = compare(test, expected);
    if (result == 0) {
        return SUCCESS;
    }
    return ERROR;
}

void buildSearchTests() {
    //5 Pass 
    printf("Build Search Test Passes: \n");
    int testOne[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testSearch(10, testOne, 9);

    int testTwo[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testSearch(8, testTwo, 9);

    int testThree[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testSearch(3, testThree, 9);

    int testFour[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testSearch(4, testFour, 9);

    int testFive[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testSearch(9, testFive, 9);

    //5 Fail
    printf("Build Search Test Fails: \n");
    //Empty Input
    int testSix[0] = {};
    testSearch(9, testSix, 0);

    //Input too large
    int testSeven[100] = { 
        1, 2, 3, 4, 5, 6, 7, 8, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
    };
    testSearch(9, testSeven, 100);

    int testEight[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testSearch(11, testEight, 10);

    int testNine[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testSearch(20, testNine, 10);

    int testTen[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testSearch(-20, testTen, 10);
}

// reverseTree takes in a root node  of a tree then recursively reverses the tree
// returns the root node
Node * reverseTree(Node * root) {
    if (root == NULL) {
        return NULL;
    }
    Node * temp = root->left;
    root->left = reverseTree(root->right);
    root->right = reverseTree(temp);
    return root;
}

int testReverse(int *expectedVals, int length) {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node * test = newTree(arr, n);
    Node* expected = malloc(sizeof(Node));
    if (test == NULL || expected == NULL) return OVERFLOW; 
    reverseTree(test);
    int result;
    result = compare(test, expected);
    if (result == 0) {
        return SUCCESS;
    }
    return ERROR;
}
//main provides buildTree an array to insert in level order into a tree
int main() {
    
}