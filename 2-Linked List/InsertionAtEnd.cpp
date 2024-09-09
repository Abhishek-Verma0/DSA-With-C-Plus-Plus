// this block of code represents how we can insert at end of list or linkes list

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Function to insert a new node at the end of the list
Node *createNode(Node *head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;      // Assign the value to the new node
    newNode->next = nullptr;    // The new node will be the last, so 'next' is set to nullptr

    if (head == nullptr)
    { // If the list is empty, the new node becomes the head
        return newNode;
    }

    Node *temp = head; // Start from the head and traverse to the end
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode; // Link the new node at the end of the list
    return head;          // Return the unchanged head
}

// Function to print the linked list
void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " "; // Print the current node's data
        curr = curr->next;         // Move to the next node
    }
}

int main()
{
    Node *head = nullptr; // Start with an empty list

    int n, num;
    cout << "How many numbers you want in the linked list? ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        head = createNode(head, num); // Insert at the end and update head
    }

    printList(head); // Print the linked list
    return 0;
}
