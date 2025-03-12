#include "linked_list.h"
#include <iostream>

using namespace std;

struct node * createLinkedList(int n) {
    if (n <= 0) {
        return NULL;
    }

    struct node * root = new node;
    root->data = 1;
    struct node * linked_list = root;

    for (int i = 2; i <= n; i++) {
        linked_list->next = new node;
        linked_list = linked_list->next;
        linked_list->data = i;
    }

    linked_list->next = root;

    return root;
}

void pointerJumping(node * head) {
    node* curr = head;
    while (curr->next != head) {
        curr = curr->next;
    }
    curr->next = NULL;
    node* end = curr;
    curr = head;
    while (curr != NULL) {
        node* next = curr->next;
        curr->next = end;
        curr = next;
    }
}

int getValue(struct node * start, int node_number, int total_elements) {
    if (node_number < 1 || node_number > total_elements) {
        return -1;
    }

    struct node * linked_list = start;
    for (int i = 1; i < node_number; i++) {
        linked_list = linked_list->next;
    }

    return linked_list->data;
}

void print(struct node * start, int total_elements) {
    struct node * linked_list = start;
    for (int i = 0; i < total_elements; i++) {
        std::cout << "Node " << i+1 << ": " << linked_list << std::endl;
        linked_list = linked_list->next;
    }
}
