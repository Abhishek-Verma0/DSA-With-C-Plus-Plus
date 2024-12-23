//  In inorder traversal we traverse left then root then rigth nodes


#include <bits/stdc++.h>

using namespace std;

class Node
{   
    public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* createTree(Node *root) 
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return nullptr;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=createTree(root->left);
    cout<<"Enter the data for the inserting in right of "<<data<<endl;
    root->right=createTree(root->right);
    return root;
}


// /inorder traversal 
void inorder(Node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


// preorder traversal
// in this we go for root first then left then right
void preorder(Node* root){
    if (root==nullptr){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);



}


//  post order traversal in this traversal we go for left then right then root

void postorder(Node* root){
    if(root==nullptr){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node *root = nullptr;
//     creating tree
    root = createTree(root);

cout<<"inorder traversal "<<endl;
inorder(root);
cout<<endl;

cout<<"Pre order traversal "<<endl;
preorder(root);
cout<<endl;
cout<<"Post order traversal  "<<endl;

postorder(root);



}