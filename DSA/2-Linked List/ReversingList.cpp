// reversing the list and printing in the reverse order
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

// function to reverse the linked list
Node *reverse(Node *head)
{
    Node *prev = nullptr; // initaly no previous nodes
    Node *curr = head;    // starting from very first node
    Node *next = nullptr; // this is gonna to store next node temporary
    // traverse the linked list
    while (curr != nullptr)
    {
        next = curr->next; // store the next node
        curr->next = prev; // reverse the current node pointer
        prev = curr;       // Move prev one step forward
        curr = next;       // Move curr one step forward
    }
    return prev; // after the loop the prev is going to be new head of the linked list
}

//  function to print the linked list 
void printList(Node* head){
    Node* curr= head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }

}

int main()
{
    Node* head= nullptr;
    int n,num;
    cout<<"Enter the number of nodes for the  linked list :: " ;
    cin>>n;
    cout<<"Enter the data for the nodes which you want the data :: ";
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        head=createNode(head,num);
    }
    cout<<"Printing the list before reversing :: ";
    printList(head);
    cout<<endl;
    cout<<"Printing after reversing list :: ";
    head=reverse(head);
    printList(head);
    
}