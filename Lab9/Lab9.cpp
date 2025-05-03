#include "lab9.h"

// Node constructor
Node::Node(string label) : label{label} {
    cout << "Node created [" << label << "] at " << this << endl;
}

// Node destructor
Node::~Node() { 
    cout << "Node [" << label << "] destroyed" << endl; 
}

// SERVER builds a circular list
void CircularList::SERVER_initializeList(const vector<string> &labels)
{
    if (labels.empty())
        return;

    head = make_shared<Node>(labels[0]);
    shared_ptr<Node> temp = head;
    all_nodes.push_back(head);

    for (size_t i = 1; i < labels.size(); ++i)
    {
        auto freshNode = make_shared<Node>(labels[i]);
        temp->nextNode = freshNode;
        all_nodes.push_back(freshNode);
        temp = freshNode;
    }

    temp->nextNode = head; // Make the list circular
}

// SERVER clears the list
void CircularList::SERVER_clearList()
{
    all_nodes.clear();
    head = nullptr;
}

// SERVER prints using shared_ptr traversal
void CircularList::SERVER_displayList()
{
    if (!head)
        return;

    auto walker = head;
    cout << "\n[SERVER] Current list:\n";
    for (size_t i = 0; i < 6; i++)
    {
        cout << "[" << walker->label << "] : use_count: " << walker.use_count() 
             << " address: " << walker.get()
             << " next (shared_ptr): " << walker->nextNode.lock().get() << endl;

        walker = walker->nextNode.lock();
    }
}

// CLIENT prints using weak_ptr traversal
void CircularList::CLIENT_displayList()
{
    if (!head)
    {
        cout << "Client sees empty list.\n";
        return;
    }

    auto walker = head;
    cout << "\n[CLIENT] Attempting to display:\n";
    for (size_t i = 0; i < 6; i++)
    {
        if (!walker)
        {
            cout << "Client node missing.\n";
            break;
        }

        cout << "[" << walker->label << "] : use_count: " << walker.use_count()
             << " address: " << walker.get()
             << " next (weak_ptr): ";

        auto nextShared = walker->nextNode.lock();
        if (nextShared)
        {
            cout << nextShared.get() << endl;
            walker = nextShared;
        }
        else
        {
            cout << "No shared_ptr available (expired)\n" << endl;
            break;
        }
    }
}

// Testing framework
TEST_CASE("Lab 9: weak_ptrs in Circular List") 
{
    vector<string> labels = {"zero", "one", "two", "three", "four", "five"};
    CircularList myList;
    myList.SERVER_initializeList(labels);
    myList.SERVER_displayList();
    myList.CLIENT_displayList(); // Before deletion
    myList.SERVER_clearList();
    myList.CLIENT_displayList(); // After deletion
}
