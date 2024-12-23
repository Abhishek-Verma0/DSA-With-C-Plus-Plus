#include<iostream>
using namespace std;

// You are using GCC
struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* tree(int data)
{
    Node* newnode=new Node;
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}
void preorder(Node* root)
{
    if(root==nullptr)
    {
        cout<<".....";
        return;
    }
    Node* stack[10];
    int top=-1;
    Node* ptr=root;
    while(ptr!=nullptr)
    {
        cout<<ptr->data;
        if(ptr->right!=nullptr)
        {
            top=top+1;
            stack[top]=ptr->right;
        }
        ptr=ptr->left;
    }
    if(top!=-1)
    {
        ptr=stack[top];
        top--;
    }
}

int main()
{
    Node* root=tree(1);
    root->left=tree(2);
    root->right=tree(3);
    root->left->left=tree(4);
    root->left->right=tree(5);
    root->right->left=tree(6);
    root->right->right=tree(7);
    preorder(root);
    return 0;
    
}