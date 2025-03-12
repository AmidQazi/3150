#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linked_list.h"

TEST_CASE("Test createLinkedList and print") {
    struct node * head = createLinkedList(5);
    CHECK(head != nullptr);
    print(head, 5);
    // Check if the last element points to itself
    struct node * lastNode = head;
    for (int i = 0; i < 4; i++) {
        lastNode = lastNode->next;
    }
    CHECK(lastNode->next == head);
}

TEST_CASE("Test pointerJumping and getValue") {
    struct node * head = createLinkedList(5);
    pointerJumping(head);
    CHECK(getValue(head, 3, 5) == 5);
    CHECK(getValue(head, 5, 5) == 5);
    CHECK(getValue(head, 4, 5) == 5);
}

TEST_CASE("Test move constructor") {
    struct node* original = createLinkedList(5);
    struct node* moved = new node(std::move(*original));
    CHECK(moved->data == 1); // Assume node 1 is the start
    CHECK(original->data == 0); // Original should be altered

    // Clean up
    delete original;
    delete moved;
}

TEST_CASE("Test move assignment") {
    struct node* original = createLinkedList(5);
    struct node* moved = new node;
    *moved = std::move(*original);
    CHECK(moved->data == 1);
    CHECK(original->data == 0); // Original should be altered

    // Clean up
    delete original;
    delete moved;
}

