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


void main() {
    
}