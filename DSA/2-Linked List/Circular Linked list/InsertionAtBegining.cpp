


#include<bits/stdc++.h>
using namespace std;
 struct Node{
    int data;
    Node* next;
 };

 Node* createNode(Node* head,int value){
    Node* newNode= new Node();
    newNode->data=value;
    if(head==nullptr){
        newNode->next=newNode;
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    return newNode;
 }

 void printList(Node* head){
    Node* curr=head;
    do{
       cout<<curr->data<<" ";
       curr=curr->next; 
    }
    while(curr!=head);
 }


 int main(){
    Node* head=nullptr;
    int n,num;
    cout<<"Enter the number of nodes you want in the linked list :: ";
    cin>>n;
    cout<<"Enter the values for the nodes :: ";
    for(int i=0;i<n;i++){
        cin>>num;
        head=createNode(head,num);
    }

    cout<<"Printing the circular linked insertion at begining :: ";
    printList(head);
 }