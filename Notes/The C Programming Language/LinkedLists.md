# Linked Lists


## Declaring a linked list
typedef struct node {
    int val;
    struct node * next;
} node_t;

Linked lists have a few advantages over arrays:

    Items can be added or removed from the middle of the list
    There is no need to define an initial size
