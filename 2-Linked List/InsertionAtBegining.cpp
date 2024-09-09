
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};


Node* createNode(Node* head, int value){
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=head;
    return newNode;
}

void display(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}


int main(){
    Node* head= nullptr;
    int n,num;
    cout<<"Enter the number of elements you want in the linked list :: ";
    cin>>n;
    cout<<"Enter the elements which you want in the linked list :: ";
    for(int i=0;i<n;i++){
        cin>>num;
        head=createNode(head,num);
    }
    display(head);
}