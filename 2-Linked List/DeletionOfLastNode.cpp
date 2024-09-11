// here we are going to delete the very last element of the linked list or we can say deletion of the last node 
// we can achieve this by traversing to the second last node and delete the last node and assign the second last node next to nullptr to mark end of the linked list 

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
        cout << curr->data << " ";
        curr = curr->next;
    }
}

// ******************function for  deletion of the last node of the linked list
Node *deletelast(Node *head)
{
    if (head == nullptr)  // if list is empty 
    {
        return nullptr;
    }

    if (head->next == nullptr)  // is list has only one node 
    {
        delete head;  // list becomes empty
        head = nullptr;
        return nullptr;
    }
    Node *temp = head;
    while (temp->next->next != nullptr)  
    {
        temp = temp->next; // traverses to the second last node of the list
    }
    delete temp->next;  // delete the last node
    temp->next = nullptr;  // set the next of second last node to nullptr to determine the end of list 
    return head;
}





int main(){
    int n,num;
    Node* head=nullptr;
    cout<<"Enter the number of nodes you want in linked list :: ";
    cin>>n;
    cout<<"Enter the data to be stored in the linked list :: ";
    for(int i=0;i<n;i++){
        cin>>num;
        head=createNode(head,num);
    }
    cout<<"Printing the linked list before deleting the tail or very last node :: ";
    printList(head);
    cout<<endl;
    cout<<"Printing the linked list after deletion of the tail or very last node of the linked list :: ";
    deletelast(head);
    printList(head);
}