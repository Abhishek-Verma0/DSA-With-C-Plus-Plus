/**
 *  It is dynamic means it's size can grow or shrink at runtime
 */

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *enq(Node *head, int value)
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

Node *deq(Node *head)
{
    if (head == nullptr)
    {
        cout<<"Is empty ";
        return nullptr;
    }
    cout<<"dequed "<<head->data<<endl;
    Node* temp= head;
    head=head->next;
    delete temp;
   return head;
    
}


int main(){
    Node* head=nullptr;
    int n,val;
    cout<<"Enter the max values to be in the queue ::";
    cin>>n;
    cout<<"Enter the values to be in the queue :: ";
    for(int i=0;i<n;i++){
        cin>>val;
        head=enq(head,val);
    }

    
    for(int i=0;i<n;i++){
        head=deq(head);
    }
}