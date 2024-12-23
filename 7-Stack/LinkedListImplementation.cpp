
/** Here we are going to use linked list for the implemenation of stack 
 * there are some things we need to keep in mind while doing this 
 * in linked list implementation we need to check for the underflow condition as overflow will not occur because it resizes dynamically
 * but if we want we can also check for the oveflow by giving the a max size condition then we can check for that 
 */



#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

};

Node* pus(Node* head,int value,int &size,int maxsize){
    if(size==maxsize){
        cout<<"Overflow";
        return  head;

    }

    Node* newNode= new Node();
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    size++;
    cout<<"Pushed "<<value<<" onto the stack."<<endl;
    return  head;

}

void print(Node* head){
    if(head==nullptr){
        cout<<"Stack is Empty .... underflow ";
        return;
    }
    Node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<"  is popped out of stack "<<endl;
        curr=curr->next;
    }
}



int main(){
    Node* head= nullptr;
    int n,val;
    int size=0;
    cout<<"Enter the max number of elements you want to store in the stack :: ";
    cin>>n;
    cout<<"Enter the elemnets to store in stack :: ";
    for(int i=0;i<n;i++){
        cin>>val;
        head=pus(head,val,size,n);
    }

    // cout<<"Popping out the elements from stack :: "<<endl;
    print(head);
}