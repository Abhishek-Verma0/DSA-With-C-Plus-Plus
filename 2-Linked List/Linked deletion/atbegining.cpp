#include<bits/stdc++.h>

using namespace std;


struct Node{
    int data;
    Node* next;
};

Node* createNode(Node* head,int value){
    Node* newNode= new Node();
    newNode->data=value;
    newNode->next=nullptr;

    if(head==nullptr){
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

//  deltion at beg;
Node* delBeg(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    Node *temp=head;
    head=head->next;
    delete temp;
    return head;
}

void display(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main(){
    Node* head=nullptr;
    int n,value;

    cout<<"Enter number of node :: ";
    cin>>n;
    cout<<"enter the value for the nodes :: ";
    for(int i=0;i<n;i++){
        cin>>value;
        head=createNode(head,value);
    }

    head=delBeg(head);
    cout<<"After deletion of first element ";
    display(head);
}