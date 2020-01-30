#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// use macros to define alloc failure and return 
// #define ALLOC_NODE 

#define SUCCESS 0
#define ERROR -1
#define OVERFLOW -2
#define EMPTY -3

#define LIMIT 10

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
bool compare(Node * updated, Node * expected) {
    if (updated == NULL && expected == NULL) return true;
    if(NULL != updated && NULL != expected) return compare(updated->left, expected->left) && compare(updated->right, expected->right) && (updated->value == expected->value);
    return false;
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


// searchNode takes in a root node and a value to find
// if/else figures out which branch the node would be in based on value
// returns 0 if value is successfully found 
Node * searchNode(Node * root, int value, int * i) {
    if (root == NULL) {
        printf("Root node is empty.");
        return root;
    } 
    if (value < root->value) {
        root->left = searchNode(root->left, value, i);
    } else if (value > root->value) {
        root->right = searchNode(root->right, value, i);
    } else if (root->left && root->right){
        Node * temp = smallestNode(root->right);
        root->value = temp->value;
        root->right = searchNode(root->right, root->value, i);
    } else {
        *i = SUCCESS;
        return 0;
    }
    return root;
}

// deleteNode takes in a root node and a value to delete 
// if/else figures out which branch the node would be based on value
// returns root of updated tree
Node * deleteNode(Node * root, int value, int * i) {
    if (root == NULL) {
        return root;
    } 

    if (value < root->value) {
        root->left = deleteNode(root->left, value, i);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value, i);
    } else if (root->left && root->right){
        Node * temp = smallestNode(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, root->value, i);
    } else {
        Node * temp = root;
        if (root->left == NULL) {
            root = root->right;
        } else if (root->right == NULL) {
            root = root->left;
        }
        *i = SUCCESS;
        free(temp);
    }
    return root;
}

//testDelete
int testDelete(int value,int *testVals, int *expectedVals, int n, int length) {
    Node * test = newTree(testVals, n);
    Node* expected = newTree(expectedVals, length);
    if (test == NULL || expected == NULL) return OVERFLOW; 
    int success, search = 5;
    searchNode(test, value, &search);
    printf("SUCCESS: %d \n", search);
    if (search != SUCCESS) {
        printf("The value %d could not be deleted from the Tree successfully because it is not present. \n", value);
        return ERROR;
    }
    deleteNode(test, value, &success);
    if (success == SUCCESS) {
        if (compare(test, expected)) {
            printf("The value %d was deleted from the Tree successfully! \n", value);
            return SUCCESS;  
        }
    }
    printf("The value %d could not be deleted from the Tree successfully. \n", value);
    return ERROR;
}

void buildDeleteTests() {
    //5 Pass 
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    printf("Build Delete Test Passes: \n");
    int testOne[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; 
    testDelete(10, arr, testOne, n, 9);

    int testTwo[9] = { 1, 2, 3, 4, 5, 6, 7, 9, 10 }; 
    testDelete(8, arr, testTwo, n, 9);

    int testThree[9] = { 1, 2, 4, 5, 6, 7, 8, 9, 10 }; 
    testDelete(3, arr, testThree, n, 9);

    int testFour[9] = { 1, 2, 3, 5, 6, 7, 8, 9, 10 }; 
    testDelete(4, arr, testFour, n, 9);

    int testFive[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 10 }; 
    testDelete(9, arr, testFive, n, 9);

    //5 Fail
    printf("Build Delete Test Fails: \n");
    //Empty Input
    int arrSix[0] = {};
    int testSix[0] = {};
    testDelete(9, arrSix, testSix, 0, 0);

    //Input too large
     int arrSeven[100] = { 
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
    testDelete(9, arrSeven, testSeven,100, 99);

    int testEight[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testDelete(11, testEight, testEight, 10, 10);

    int testNine[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testDelete(20, testNine, testNine, 10, 10);

    int testTen[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    testDelete(-20, testTen, testTen, 10, 10);
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
        printf("The test case was reversed successfully! \n");
        return SUCCESS;
    }
    printf("The test case was not reversed successfully. \n");
    return ERROR;
}

// problem: how many interesting reverse test cases are there...?
void buildReverseTests() {
    //5 Pass 
    printf("Build Reverse Test Passes: \n");
    int resultOne[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    testReverse(resultOne, 10);

    int resultTwo[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    testReverse(resultTwo, 10);

    int resultThree[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    testReverse(resultThree, 10);

    int resultFour[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    testReverse(resultFour, 10);

    int resultFive[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    testReverse(resultFive, 10);

    //5 Fail
    printf("Build Reverse Test Fails: \n");
    //Empty List
    int resultSix[0] = {};
    testReverse(resultSix, -7);

    //Input too large
    int resultSeven[100] = { 
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
        10, 9, 8, 7, 6, 5, 4, 3, 2, 1,
       10, 9, 8, 7, 6, 5, 4, 3, 2, 1
    };
    testReverse(resultSeven, 100);

    int resultEight[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    testReverse(resultEight, 0);

    int resultNine[10] = { -120, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    testReverse(resultNine, -6);

    int resultTen[10] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    testReverse(resultTen, 2);

}

//main provides buildTree an array to insert in level order into a tree
int main() {
    buildDeleteTests();
    // buildSearchTests();
    // buildReverseTests();
}