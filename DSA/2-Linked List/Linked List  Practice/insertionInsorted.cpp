

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};


Node* end(Node* head, int val){
    Node* newNode= new Node();
    newNode->data=val;
    newNode->next=nullptr;
    if(head==nullptr){
        return newNode;
    }
    
    Node* temp= head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

//  insertion in sorted way
Node* sor(Node* head,int val){
    Node* newNode= new Node();
    newNode->data=val;
    newNode->next=nullptr;
    if(head==nullptr || head->data >=val){
        
             newNode->next=head;
        return newNode;
    }
    Node* temp= head;
    
    while(temp->next!=nullptr && temp->next->data < val){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return head;
    
}



void print(Node* head){
    if(head==nullptr){
        return ;
    }
    Node* curr= head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}


int main(){
    Node* head= nullptr;
    int n,val,ch;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>val;
        head=end(head,val);
    }
    
    cin>>ch;
    head=sor(head,ch);
    print(head);
}