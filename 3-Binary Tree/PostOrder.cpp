#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *tree(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorder(root->left);
    // cout << root->data << " ";
    postorder(root->right);
    cout<<root->data<<" ";
}
Node *Tree()
{
    int data;
    cin >> data;
    if(data==-1){
        return nullptr;
    }
    Node *root = tree(data);
    cout << "Enter left child "<<data<<": ";
    root->left = Tree();
    cout << "enter right child :: "<<data<<": ";
    root->right = Tree();
    return root;
}



int main(){
    Node* root=Tree();
    postorder(root);
    return 0;
    }