#include <iostream>
#include <limits>
using namespace std;

struct Node
{
    float value;
    Node *next;
};

// Pass head by reference so these functions can change the real head pointer.
void addNodeFront(Node *&, float);
void addNodeTail(Node *&, float);
void deleteNode(Node *&, int);
void insertNode(Node *&, int, float);
void deleteList(Node *&);
void output(Node *);

int main()
{
    Node *head = nullptr;

    int choice = 0;
    float value;
    int position;

    while (choice != 7)
    {
        cout << "\nLinked List Menu" << endl;
        cout << "1. Add node to front" << endl;
        cout << "2. Add node to end" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Insert a node" << endl;
        cout << "5. Delete the list" << endl;
        cout << "6. Print the list" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice --> ";

        cin >> choice;

        // Make sure the user enters a valid menu number.
        if (!cin || choice < 1 || choice > 7)
        {
            cout << "Invalid choice. Try again." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            choice = 0;
            continue;
        }

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;

            if (!cin)
            {
                cout << "Invalid value." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            addNodeFront(head, value);
        }
        else if (choice == 2)
        {
            cout << "Enter value: ";
            cin >> value;

            if (!cin)
            {
                cout << "Invalid value." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            addNodeTail(head, value);
        }
        else if (choice == 3)
        {
            output(head);

            if (!head)
            {
                continue;
            }

            cout << "Which node to delete? ";
            cin >> position;

            if (!cin || position <= 0)
            {
                cout << "Invalid position." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            deleteNode(head, position);
        }
        else if (choice == 4)
        {
            output(head);

            cout << "After which node should the new node be inserted? ";
            cin >> position;

            if (!cin || position < 0)
            {
                cout << "Invalid position." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            cout << "Enter value: ";
            cin >> value;

            if (!cin)
            {
                cout << "Invalid value." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            insertNode(head, position, value);
        }
        else if (choice == 5)
        {
            deleteList(head);
            cout << "List deleted." << endl;
        }
        else if (choice == 6)
        {
            output(head);
        }
    }

    // Clean up any nodes left before the program ends.
    deleteList(head);

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

void insertNode(Node *&head, int position, float value)
{
    Node *newNode = new Node;

    newNode->value = value;

    if (!head || position <= 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;

    for (int i = 1; i < position && current->next; i++)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteList(Node *&head)
{
    Node *current = head;

    while (current)
    {
        head = current->next;
        delete current;
        current = head;
    }

    head = nullptr;
}

void output(Node *hd)
{
    if (!hd)
    {
        cout << "Empty list." << endl;
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
}