/**
 * Header linked list is  same as singly linked list  but one modification it has special node at begining callled as header NOde
 * It includes a special head node, often called a "dummy node" or "sentinel node," that does not contain actual data but serves as the starting point of the list.
 * this header node is pointer to the next node 
 */



/*********************************Grounded Header Liniked list  ***************************************************/



#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to create a new node
Node *createNode(int value)
{
    Node *node = new Node(); // Allocate memory for the new node
    node->data = value;    // Assign data to the node
    node->next = nullptr;    // Initialize next pointer to null
    return node;             // Return the created node
}

// Inserts a node at the end of the linked list and returns the updated list
Node *insert(Node *header, int value)
{
    Node *curr = header; // Start from the header node
    while (curr->next != nullptr)
        curr = curr->next; // Traverse to the end of the list

    Node *newNode = createNode(value); // Create a new node with the data
    curr->next = newNode;          // Link the new node at the end of the list
    return header;                 // Return the updated header
}

// Function to print the linked list
void printList(Node *header)
{
    Node *curr = header->next; // Skip the header node
    while (curr != nullptr)
    {
        cout << curr->data << " "; // Print the data of each node
        curr = curr->next;         // Move to the next node
    }
    cout << endl;
}

int main()
{
    // Create a header node
    Node *header = createNode(0); // Header node with dummy data (0)

    int n; // Number of elements
    cout << "How many numbers you want to insert into the linked list? ";
    cin >> n;

    // Input the elements using a for loop
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;                   // Read the number
        header = insert(header, num); // Insert into the linked list
    }

    // Print the linked list
    cout << "Linked list: ";
    printList(header);

    return 0;
}