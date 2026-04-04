// Insertion at begining means we are going to place every new element before the old one
// for example  we give input 1 2 3 4 5  then it will be like    5 4 3 2 1

#include <bits/stdc++.h>    // it is  superset of all the library present in the c++
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// function to insert new node at the begining
Node *createNode(Node *head, int value)
{
    Node *newNode = new Node(); // creating  the node
    newNode->data = value;      // assign value to the new node
    newNode->next = head;       // Point the new node's 'next' to the current head (inserting at beginning)
    return newNode;             // Return the new node as the new head
}

//  function to display the created linked list or the nodes

void display(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " "; // Printing the current node's data
        curr = curr->next;         // moving to the next node
    }
}

int main()
{
    Node *head = nullptr; // starting with an empty list
    int n, num;
    cout << "Enter the number of elements you want in the linked list :: ";
    cin >> n;
    cout << "Enter the elements which you want in the linked list :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        head = createNode(head, num); // insert at begining and update
    }
    display(head); // printing the linked list
}