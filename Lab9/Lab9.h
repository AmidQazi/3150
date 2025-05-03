#ifndef LAB9_H
#define LAB9_H

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./include/doctest.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

// Node structure representing each element in the list
struct Node {
    string label;
    Node(string label);

    weak_ptr<Node> nextNode; // weak_ptr to avoid ownership cycle
    ~Node();
};

// LinkedList class managing the node chain
class CircularList {
public:
    void SERVER_initializeList(const vector<string> &labels);
    void SERVER_clearList();
    void SERVER_displayList();
    void CLIENT_displayList();

private:
    shared_ptr<Node> head;  // Root of the list
    vector<shared_ptr<Node>> all_nodes; // To keep shared ownership
};

#endif

