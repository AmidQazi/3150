#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

struct Node {
    string name;
    shared_ptr<Node> next;           // shared_ptr for SERVER
    weak_ptr<Node> weak_next;        // weak_ptr for CLIENT

    Node(string name) : name{name} {}
    ~Node() {
        cout << "Node [" << name << "] destructor" << endl;
    }
};

class LinkedList {
private:
    vector<string> names = {"zero", "one", "two", "three", "four", "five"};
    shared_ptr<Node> root = nullptr;
    int numberOfNodes = names.size();

public:
    void SERVER_buildCircularLinkedList() {
        root = make_shared<Node>(names[0]);
        shared_ptr<Node> node = root;

        for (int i = 1; i < numberOfNodes; i++) {
            node->next = make_shared<Node>(names[i]);
            node = node->next;
        }

        // Make circular
        node->next = root;

        // Assign weak_ptrs
        shared_ptr<Node> walker = root;
        for (int i = 0; i < numberOfNodes; i++) {
            walker->weak_next = walker->next;
            walker = walker->next;
        }
    }

    void SERVER_printLinkedList() {
        cout << "Server (step 2):" << endl;
        shared_ptr<Node> node = root;
        for (int i = 0; i < numberOfNodes; i++) {
            cout << "[" << node->name << "] : use_count: " << node.use_count()
                 << " address: " << node.get()
                 << " next (from shared_ptr): " << node->next.get() << endl;
            node = node->next;
        }
        cout << endl;
    }

    void CLIENT_printLinkedList() {
        cout << "Client (step 3 or 5):" << endl;
        shared_ptr<Node> node = root;
        for (int i = 0; i < numberOfNodes; i++) {
            cout << "[" << node->name << "] : use_count: " << node.use_count()
                 << " address: " << node.get();

            shared_ptr<Node> next = node->weak_next.lock();
            if (next) {
                cout << " next (from weak_ptr): " << next.get() << endl;
                node = next;
            } else {
                cout << " next (from weak_ptr): 0" << endl;
                cout << "Yipes! shared_ptr not available" << endl;
            }
        }
        cout << endl;
    }

    void SERVER_deleteCircularLinkedList() {
        cout << "Server is deleting the shared_ptrs (step 4)" << endl;
        root = nullptr;
    }
};
