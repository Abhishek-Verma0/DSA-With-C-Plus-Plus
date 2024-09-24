//  here we are going to delete the very first node of the linked list or we can say the head part of the linked list

#include<bits/stdc++.h>
using namespace std;


struct Node{
    int data;
    Node* next;
};

Node* createNode(Node* head,int value){
    Node* newNode=new Node();
    newNode->data=value;
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

// ********************************function to delete very first node of an linked list

Node* deleteFirst(Node* head){
    if(head== nullptr)
    { // If the list is empty, return nullptr
        return nullptr;
    }

    Node *temp = head; // Store the current head in a temporary pointer
    head = head->next; // Move the head pointer to the next node
    delete temp;       // Delete the old head node
    return head; // return new head of the list 
}


void print(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}


int main(){
    int n,num;
    Node* head= nullptr;
    cout<<"Enter the number of nodes a linked list will have :: ";
    cin>>n;
    cout<<"Enter the elements to store in the linked list :: ";
    for(int i=0;i<n;i++){
        cin>>num;
        head=createNode(head,num);
    }

    cout<<"Printing the linked list before deletion of the head node or very first node :: ";
    print(head);
    cout<<endl;
    head=deleteFirst(head);
    cout<<"Printing the linked list after the deletion of very first node or head :: ";
    print(head);
}
