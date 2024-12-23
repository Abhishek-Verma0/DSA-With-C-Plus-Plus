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

void display(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

//  /**********************function for deletion at end */

Node* delEnd(Node* head){
    if(head==nullptr){
        return nullptr;
    }

    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return nullptr;
    }
    Node* temp=head;

    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
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

    cout<<"After deletion of elemnet at end :: ";
    head=delEnd(head);
    display(head);


}