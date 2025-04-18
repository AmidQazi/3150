#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int data;
    struct node* next;

    // Move constructor
    node(node&& other) noexcept;

    // Move assignment operator
    node& operator=(node&& other) noexcept;
};


struct node * createLinkedList(int n);

void pointerJumping(struct node * head);

int getValue(struct node * start, int node_number, int total_elements);

void print(struct node * start, int total_elements);

#endif 
