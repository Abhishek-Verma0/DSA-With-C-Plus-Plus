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
// function to delete the very first node of an linked list 
Node* deleteHead(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

Node *deleteKthNode(Node *head, int k)
{
    // checking whether the given linked list is empty or not 
    if (head == nullptr)
    {
        return nullptr;
    }

    //  if we need to delete the very first node or head of the linked list  we will call the function to delete the very first node of the linked list
    if (k == 0)
    {
        return deleteHead(head);
    }
    Node* temp=head;
    // now we need to traverse just before   the node which we want to delete 
    for(int i=0;i<k-1 && temp!=nullptr;i++){
            temp=temp->next;
    }


    //  checking whether given node is in the list or not checking for out of bound 
    if(temp==nullptr || temp->next ==nullptr){
        return head;
    }

    Node* toDelete= temp->next;
    temp->next= temp->next->next;
    delete toDelete;
    return head;

}


int main(){
    int n, num;
    Node* head= nullptr;  // initially we declare a empty linked list 

    cout<<"Enter the number of nodes for the linked list :: ";
    cin>>n;
    cout<<"Enter the data for the nodes of the linked list :: ";
    for(int i=0;i<n;i++){
        cin>>num;
        head=createNode(head,num);
    }
    cout<<"Printing the list before deletion of node at specified place :: ";
    printList(head);
    cout<<endl;
    int ind;
    cout<<"Enter the position of node which you want to delete from the linked list :: ";
    cin>>ind;
    cout<<"Printing the linked list after the deletion of the Node at the specified position :: ";
    head=deleteKthNode(head,ind);
    printList(head);
}