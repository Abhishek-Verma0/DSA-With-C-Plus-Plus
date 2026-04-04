#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int d){
        data=d;
        prev=next=nullptr;
    }
};


// function for insertion at begining in double linked list
Node* insertBeg(Node* head,int value){
    Node* newNode=new Node(value);
    // make next of it as head
    newNode->next=head;
    if(head!=nullptr){
        head->prev=newNode;
    }
    return newNode;
}


//  function to insert at end of double linked list 

Node* insertEnd(Node* head,int value){
    Node* newNode= new Node(value);
    if(head==nullptr){
        head=newNode;
    }
    else{
        Node* curr=head;
        while(curr->next!=nullptr){
            curr= curr->next;
        }
        curr->next=newNode;
        newNode->prev=curr;
    }
    return head;
}


// insertion at specific position
Node* insertAtspecific(Node* head,int pos,int value){
    Node* newNode=new Node(value);
    if(pos==1){
        newNode->next=head;
        if(head!=nullptr){
            head->prev=newNode;
        }
        head=newNode;
        return head;
    }
    Node* curr=head;
    // traverse the list to find the node before the insertion point 
    for(int i=1;i<pos-1 && curr!=nullptr;i++){
        curr=curr->next;
    }

    // if pos is out of bound
    if(curr==nullptr){
        cout<<"Position is out of bound "<<endl;
        delete newNode;
        return head;
    }
    newNode->prev=curr;
    newNode->next=curr->next;
    curr->next=newNode;
    if(newNode->next!=nullptr)
    {
        newNode->next->next->prev=newNode;
    }
    return head;
}

// forward traversal
void forward(Node* head){
     Node* curr=head;
     while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
     }

     cout<<endl;
}


//  function for backward traversal of double linked list 

void backward(Node* tail){
    Node* curr= tail;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->prev;
    }

}


// function to find the length of the double linked list 

int findLength(Node* head){
    int count=0;
    for(Node* curr= head;curr!=nullptr;curr=curr->next){
        count++;
    }
        return count;
}