/* 
   What is circular linked list ?? so it is a type of linked list whose tail points to the head rather than pointing to nullptr
*/ 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};
// // Function to create a new node and insert it into the circular linked list
Node* createNode(Node* head,int value){
    Node* newNode= new Node();
    newNode->data=value;
    newNode->next=nullptr;

    if(head==nullptr){
        // If the list is empty, the new node points to itself
        newNode->next=newNode;
        return newNode;
    }
    Node* temp=head;
    // Traverse the list to find the node which points to head
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    return head;
}

// Function to print the circular linked list
void printList(Node* head){
    Node* curr= head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    while(curr!=head);
}


int main(){
    Node* head=nullptr;
    int n,num;
    cout<<"Enter the number of nodes you want in the circular linked list :: ";
    cin>>n;
    cout<<"Enter the values for the nodes to be stored in circular linked list :: ";
    for(int i=0;i<n;i++){
        cin>>num;
        head=createNode(head,num);
    }
    cout<<endl;
    cout<<"Printing the circular linked list :: ";
    printList(head);
}

