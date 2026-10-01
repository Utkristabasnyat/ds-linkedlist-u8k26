#include <iostream>
using namespace std;

const int SIZE = 7;

struct Node
{
    float value;
    Node *next;
};

// Pass head by reference so these functions can change the real head pointer.
void addNodeFront(Node *&, float);
void addNodeTail(Node *&, float);
void deleteNode(Node *&, int);
void output(Node *);

int main()
{
    Node *head = nullptr;
    int count = 0;

    // Create a linked list of random numbers.
    for (int i = 0; i < SIZE; i++)
    {
        int tmp_val = rand() % 100;
        addNodeFront(head, tmp_val);
    }

    output(head);

    // Test adding a node to the end.
    addNodeTail(head, 500);

    cout << "After adding 500 to the end:" << endl;
    output(head);

    // Delete a node chosen by the user.
    cout << "Which node to delete? " << endl;
    output(head);

    int entry;

    cout << "Choice --> ";
    cin >> entry;

    deleteNode(head, entry);

    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;

    count = 1;
    Node *current = head;

    while (current)
    {
        cout << "[" << count++ << "] "
             << current->value << endl;

        current = current->next;
    }

    cout << "Choice --> ";
    cin >> entry;

    current = head;
    Node *prev = nullptr;

    for (int i = 0; i < entry; i++)
    {
        prev = current;
        current = current->next;
    }

    // Insert a node between prev and current.
    Node *newnode = new Node;

    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr)
    {
        head = newnode;
    }
    else
    {
        prev->next = newnode;
    }

    output(head);

    // Delete the linked list.
    current = head;

    while (current)
    {
        head = current->next;
        delete current;
        current = head;
    }

    head = nullptr;

    output(head);

    return 0;
}

void addNodeFront(Node *&head, float value)
{
    Node *newNode = new Node;

    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

void addNodeTail(Node *&head, float value)
{
    Node *newNode = new Node;

    newNode->value = value;
    newNode->next = nullptr;

    if (!head)
    {
        head = newNode;
        return;
    }

    Node *current = head;

    while (current->next)
    {
        current = current->next;
    }

    current->next = newNode;
}

void deleteNode(Node *&head, int position)
{
    if (!head || position <= 0)
    {
        return;
    }

    Node *current = head;
    Node *prev = nullptr;

    for (int i = 1; i < position && current; i++)
    {
        prev = current;
        current = current->next;
    }

    if (!current)
    {
        return;
    }

    if (prev == nullptr)
    {
        head = current->next;
    }
    else
    {
        prev->next = current->next;
    }

    delete current;
}

void output(Node *hd)
{
    if (!hd)
    {
        cout << "Empty list.\n";
        return;
    }

    int count = 1;
    Node *current = hd;

    while (current)
    {
        cout << "[" << count++ << "] "
             << current->value << endl;

        current = current->next;
    }

    cout << endl;
}