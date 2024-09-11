//  we are going to delete now nodes by the given value means .... user gives input a value if that value matches any of the value of the linked list  then delete that node 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(Node*head, int value){
    Node* newNode=new Node();
    newNode->data= value;
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

void printList(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<"  ";
        curr=curr->next;
    }
}
//function to delete the very first value or head node
Node* deleteHead(Node* head){
    if(head==nullptr){
        return nullptr;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;

}

//  function to delete nodes by the value 
Node* deleteByValue(Node* head, int value){

    //  we check whether the given linked list is empty or not 
    if(head==nullptr){
        return nullptr; // if the linked list is empty means head is empty then return the nullptr
    }
    if(head->data==value){
        return deleteHead(head);  // if linked list contains the value to be deleted at very first head then call the function delete head which will delete the head node of the linked list 
    }


    Node* temp=head;  // this line avoid any direct change to head node to avoid abnormal behaviour of code 

    //  traversing to just before the node which we need to delete 
    while(temp->next!=nullptr && temp->next->data!=value){
        temp=temp->next;
    }

// if we reach the end of the linked list without findiing the value 
    if(temp->next==nullptr){
        return head;
    }
//       if the node with given value found then the deletion steps 
    Node* toDelete= temp->next;  
    temp->next = temp->next->next; // link the previous node to the next
    delete toDelete;  // deletion of the desired node with given value 
    return head; // returning the original head of the linked list 
}

int main(){
    Node* head=nullptr;
    int n,num;
    cout<<"Enter the number of Nodes you want in Linked List :: ";
    cin>>n;
    cout<<"Enter the values to be inserted in the linked list :: ";
    for(int i=0;i<n;i++){
        cin>>num;
        head=createNode(head,num);
    }
    cout<<"Printing the linked list before deleting ";
    printList(head);
    int del;
    cout<<endl;
    cout<<"Enter the value that you want to delete from the above linked list :: ";
    cin>>del;
    cout<<"Printing the linked list after the deletion of the desired value from the linked list : ";
    head=deleteByValue(head,del);
    printList(head);
}