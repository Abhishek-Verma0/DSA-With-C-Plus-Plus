#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=nullptr;
        this->right=nullptr;
    }
};

Node* insert(Node* root,int data){
    if(root==nullptr){
        root=new Node(data);
        return root;
    }
    if(data > root->data){
        root->right=insert(root->right,data);
    }
    else{
        root->left=insert(root->left,data);
    }
    return root;
}

void createBST(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
       root= insert(root,data);
        cin>>data;
    }
}

//  min 
Node* min(Node* root){
    Node * temp=root;
    while(temp->left!=nullptr){
        temp=temp->left;
    } 
    return temp;
}

// max
Node* max(Node* root){
    Node * temp=root;
    while(temp->right!=nullptr){
        temp=temp->right;
    }
    return temp;
}


int main(){
    Node* root=nullptr;
    createBST(root);
    cout<<"Min value is "<<min(root)->data<<endl;
    cout<<"Max value is "<<max(root)->data;
}