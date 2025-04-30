#include "LinkedList.cpp"

int main() {
    LinkedList list;

    // Step 1
    list.SERVER_buildCircularLinkedList();

    // Step 2
    list.SERVER_printLinkedList();

    // Step 3
    list.CLIENT_printLinkedList();

    // Step 4
    list.SERVER_deleteCircularLinkedList();

    // Step 5
    list.CLIENT_printLinkedList();

    return 0;
}
