//  IN BST  for every node their left nodes are less than root and right nodes is greater than right


//// **************INorder of BST is always sorted 


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

void leveOrderTraversaal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==nullptr){
            //  old level is completed treaverese
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
        cout<<temp->data<<" ";
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}



int main(){
    Node* root = nullptr;
    createBST(root);
cout<<"printing level order "<<endl;
    leveOrderTraversaal(root);
    return 0;
}



//  stack queue hashing heap array  



