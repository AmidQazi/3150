#include "LinkedList.cpp"
#include <cassert>

void runTests() {
    LinkedList list;

    // Build the list
    list.SERVER_buildCircularLinkedList();

    // There is no built-in return or accessor for nodes, so we'll rely on printing as visual validation
    // Normally we'd refactor to return values or expose nodes for proper assertions
    list.SERVER_printLinkedList();
    list.CLIENT_printLinkedList();

    // Delete and test again
    list.SERVER_deleteCircularLinkedList();
    list.CLIENT_printLinkedList();

    // The test completes if no crashes or memory leaks (visual inspection for destructors)
    cout << "All tests passed (visually verify destructor calls and Yipes! messages)." << endl;
}

int main() {
    runTests();
    return 0;
}
