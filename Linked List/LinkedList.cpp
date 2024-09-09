//  Here  we learn the singly linked list means  a node will contain the data and the link to the next node which  means address of the next node  



// list is collection of same type of data type

/* we use linked list over the array because we cannot dynamically change the size of an array at runtime if we need to insert more item than the declared size of an array */

// linked list when new node is inserted at the end

#include <bits/stdc++.h> // this import imports all the possible library in c++ advantage we do not need to import single library again and again but sometimes it may consume more time to import all not needed library
using namespace std;
//  we use structure to create nodes;
struct Node
{
    int data;
    Node *next; // a pointer to the next node of list
};

Node *createNode(int value)
{
    Node *newNode = new Node(); // this creates a new node in the list      and allocates memory using new keyword
    newNode->data = value;      // this line assigns the value to the newly created nodes
    newNode->next = nullptr;    // intializing the next pointer as the nullptr which shows the end of list
    return newNode;             // returning the new node which we have created
}
//   funtion to print the linked list which we have created
void printList(Node *head)
{
    Node *curr = head; // starting with the very first node of linked list which we say head
    while (curr != nullptr)
    {
        cout << curr->data << " "; // printiing the data of  the current node
        curr = curr->next;         // here we move towards the next node in the linked list
    }
}

int main()
{
    int n, k;
    cout << "Enter the number of Integer you want in the linked list :: ";
    cin >> n;
    Node *head = nullptr; //  intialise head with nullptr value
    Node *tail = nullptr; // initialse the tail with nullptr value or we can say the end node
    cout << "Enter the elements for the linked list :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        Node *newNode = createNode(k); // creating the node usng the createNode function which we have created earlier
        if (head == nullptr)
        {
            head = newNode; // if list is empty assign the value to the head
        }
        else
        {
            tail->next = newNode; //  link the previous last node to the next node
        }
        tail = newNode; // updating the tail of new node
    }
    printList(head); // using the earlier made printList function to print the linked list which we have created
}
