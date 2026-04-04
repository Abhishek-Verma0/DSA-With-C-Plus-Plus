#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    // Constructor
    Node(int d)
    {
        data = d;
        prev = next = nullptr;
    }
};

//  function to insert at end of double linked list

Node *insertEnd(Node *head, int value)
{
    Node *newNode = new Node(value);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }
    return head;
}


//  function for deletion at begining
Node* deleteHead(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    // temprory storage for later deletion
    Node* temp= head;
    head=head->next;
    if(head!=nullptr){
        head->prev=nullptr;
    }
    delete temp;
    return head;
}


//  function for deletion at end

Node* deleteEnd(Node* head){
    // edge cases
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    //  traverse to the last node
    Node* curr=head;
    while(curr->next!=nullptr){
        curr=curr->next;
    }
    //  update previous node's next pointer
    curr->prev->next=nullptr;
    // delete the last node
    delete curr;
    return head;
}



// deletion at specific Position 
Node* deleteSpecifiedPos(Node* head,int pos){
    //  if the list is empty
    if(!head){
        return head;
    }
    Node* curr= head;
    for(int i=1;curr && i<pos;i++){
        curr=curr->next;
    }
    //  if postion is out of range
    if(!curr){
        return head;
    }
    // update prev node next pointer
    if(curr->prev){
        curr->prev->next=curr->next;
    }
    // update next node prev
    if(curr->next){
        curr->next->prev=curr->prev;
    }
    // if node to delete is head node
    if(head==curr){
        head=curr->next;
    }
    delete curr;
    return head;
}