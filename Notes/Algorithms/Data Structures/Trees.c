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


//Note: Per Sasha's feedback traverse function would accept a function pointer
// eX: so you can do traverse(tree, print_fn)

// Was only using traverse when fiddling with code to print out and visually verify trees rather than part of the "production" code
// Am not calling it in the code otherwise so am not fully implementing Sasha's feedback but researched this method and in practice it would look something like the below

// void printFunction(Node * root) {
//     printf("%d \n", root->value);
// }

//  void (*print)(int);
//  print = &printFunction;
// traverse(root, print);
// void traverse(Node * root, *print) {
//     if (root != NULL) {
//         traverse(root->left);
//         printf("%d \n", root->value);
//         traverse(root->right);
//     }
//     return ;
// }

//Compare: traverses a list of an "updated" tree and an expected tree & compares for matching values.
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


// smallestNode
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

// largestNode
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

// testSearch takes in a test value to search for, the expected resulting Tree
// First creates a newTree with the testvalues
// Checks to see if a memory allocation resulted, if so returns OVERFLOW -2
// Next calls searchNode to see if the node in question is present in the test Tree
// Checks to see if the return result of SearchNode matches the expectedOutcome(SUCCESS or ERROR) provided by the test cases
// If both match returns a corresponding success message and return SUCCESS
// If there is a mismatch in expectations and results a corresponding error message and returns ERROR
int testSearch(int value, int expectedOutcome) {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node * test = newTree(arr, n);
    if (test == NULL) return OVERFLOW; 
    int success = ERROR;
    searchNode(test, value, &success);
    if (success == SUCCESS && expectedOutcome == SUCCESS) {
        printf("The value %d was successfully found as expected. \n", value);
        return SUCCESS;
    } else if (success == ERROR && expectedOutcome == ERROR) {
        printf("The value %d was not found as expected. \n", value);
        return SUCCESS;
    }
    printf("Mismatch: An unknown error has occurred. \n");
    return ERROR;
}

// buildSearchTests
// creates 5 test cases expected to pass the testSearch function
// creates 5 test cases expected to fail the testSearch function
void buildSearchTests() {
    //5 Pass 
    printf("Build Search Test Passes: \n");
    testSearch(10, SUCCESS);

    testSearch(8, SUCCESS);

    testSearch(3, SUCCESS);

    testSearch(4, SUCCESS);

    testSearch(9, SUCCESS);

    //5 Fail
    printf("Build Search Test Fails: \n");
    //Empty Input
    testSearch(99, ERROR);

    testSearch(-9, ERROR);

    testSearch(11, ERROR);

    testSearch(20, ERROR);

    testSearch(-20, ERROR);
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

// testDelete
// First creates a test Tree with the test values, expected tree with the expected values.
// checks to see if memory allocation failed if so returns OVERFLOW -2
// checks to see if the value in question is even present if so return SUCCESS 0 or ERROR -1
// If value is present in Tree then deleteNode function is called - if that function returns a SUCCESS code and the compare function finds both trees to be equal returns SUCCESS
// If the value is not properly deleted then an ERROR -1 is returned
int testDelete(int value,int *testVals, int *expectedVals, int n, int length) {
    Node * test = newTree(testVals, n);
    Node* expected = newTree(expectedVals, length);
    if (test == NULL || expected == NULL) {
        printf("Improper memory allocation has occurred. \n");
        return OVERFLOW; 
    }
    int search = ERROR;
    Node * temp = newTree(testVals, n);
    searchNode(temp, value, &search);
    if (search != SUCCESS) {
        printf("The value %d could not be deleted from the Tree successfully because it is not present. \n", value);
        return ERROR;
    }
    int success;
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

// buildDeleteTests
// creates 5 test cases expected to pass the testDelete function
// creates 5 test cases expected to fail the testDelete function
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

// testReverse
// First creates a test Tree with the test value 
// Then creates an expected tree with the expected values
// checks to see if memory allocation failed if so returns OVERFLOW -2
// calls helper function reverseTree on the testTree
// compares the reversed test tree against the expected tree
// if both are the same then prints a success message and returns a SUCCESS code 0
// if not, prints an error message and returns an ERROR code -1
int testReverse(int *expectedVals, int length) {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Node * test = newTree(arr, n);
    Node* expected = newTree(expectedVals, length);
    if (test == NULL || expected == NULL) {
        printf("Improper memory allocation has occurred. \n");
        return OVERFLOW; 
    }    
    reverseTree(test);
    if (compare(test, expected)) {
        printf("The test case was reversed successfully! \n");
        return SUCCESS;
    }
    printf("The test case was not reversed successfully. \n");
    return ERROR;
}

// buildReverseTests
// creates 5 test cases expected to pass the testReverse function
// creates 5 test cases expected to fail the testReverse function
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

//main calls buildDeleteTests, buildSearchTests and buildReverseTests in succession to begin the process of testing the search, reverse and delete functions
int main() {
    buildDeleteTests();
    buildSearchTests();
    buildReverseTests();
}