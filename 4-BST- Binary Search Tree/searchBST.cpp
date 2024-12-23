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


Node* insert(Node* root,int value){
    if(root==nullptr){
        return new Node(value);
    }
    if( value > root->data){
        root->right=insert(root->right,value);
    }
    else{
        root->left=insert(root->left,value);
    }
    return root;
}

void createBST(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insert(root,data);
        cin>>data;
    }
}

//  searching in binary tree  
bool search(Node* root,int val){
    if(root==nullptr){
        return false;
    }
    if(root->data==val){
        return true;
    }
    if(root->data >val){
        return search(root->left,val);
    }
    else{
        return search(root->right,val);
    }
}

int main(){
    Node* root= nullptr;

    createBST(root);
    int val;
    cin>>val;
    search(root,val);

}