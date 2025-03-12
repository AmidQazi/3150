#include <iostream>
#include "linked_list.h"

int main() {
    int n = 5;
    struct node * head = createLinkedList(n);

    std::cout << "Original linked list:" << std::endl;
    print(head, n);

    pointerJumping(head);

    std::cout << "\nLinked list after pointer jumping:" << std::endl;
    print(head, n);

    return 0;
}
