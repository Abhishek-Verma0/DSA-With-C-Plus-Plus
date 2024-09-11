// this code shows the implementation of the linked list and how we can track and delete the nodes which are at the even position 
// similar code will also be for the deleting the nodes at odd position in the linked list 


#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void insertNode(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (*head == nullptr)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


//  function to delete the nodes at even positions
void deleteEvenPositionNodes(Node **head)
{
    // checks whether the linked list is empty or it ony contains one node 
    if (*head == nullptr || (*head)->next == nullptr)
    {
        return;
    }
    // Initialize pointers and position counter
    Node *temp = *head;   // Start from the head of the list
    Node *prev = nullptr; // Previous node pointer, initially set to nullptr
    int count = 1; // position counter starting from 1
    // traverse the linked list 
    while (temp != nullptr)
    {
        if (count % 2 == 0)
        { // if position is even then delete the current node 
            prev->next = temp->next;  // this skips the current node 
            delete temp;  // this frees the memory for the current node 
            temp = prev->next; //  moves to the next node
        }
        else
        { // is postion is not even 
            prev = temp;  //move prev to the current node 
            temp = temp->next; //move temp to the next node 
        }
        count++;
    }
}
void displayLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    int size;

    cin >> size;

    for (int i = 0; i < size; i++)
    {
        int value;
        cin >> value;
        insertNode(&head, value);
    }

    cout << "Original Linked List: ";
    displayLinkedList(head);

    deleteEvenPositionNodes(&head);

    cout << "Final Linked List: ";
    displayLinkedList(head);

    Node *temp = head;
    while (head != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }

    return 0;
}