//if we want to delete the Node present at Kth position we need to check whether linked list is empty or not   if it is empty return null 
// also check if we need to delete the element from the very first node   for this we can write a seperate function for deletion of very first node or head


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(Node *head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
void printList(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout<< curr->data << " ";
        curr = curr->next;
    }
}

Node* deleteHead(Node* head){
    
}

Node *deleteKthNode(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    if (k == 0)
    {

    }
}