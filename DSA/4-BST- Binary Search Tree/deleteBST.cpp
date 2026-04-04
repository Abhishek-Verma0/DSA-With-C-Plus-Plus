

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

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        root->left = insert(root->left, value);
    }
    return root;
}

void createBST(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insert(root, data);
        cin >> data;
    }
}

//  minimum 
Node* minval(Node* root){
    Node * temp=root;
    while(temp->left!=nullptr){
        temp=temp->left;
    }
    return temp;
}

//  deletion of node from a tree

Node *deleteBST(Node *root, int val)
{
    if (root == nullptr)
    {
        return root;
    }

    if(root->data==val){
        //0 child
        if(root->left==nullptr && root->right==nullptr){
            delete root;
            return nullptr;
        }
        // 1 child has two case one for left and one for right

        // left child
        if(root->left!=nullptr && root->right==nullptr){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        //right chils
        if(root->right!=nullptr && root->left==nullptr){
            Node* temp= root;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=nullptr && root->right!=nullptr){
            int min=minval(root->right)->data;
            root->data=min;
            root->right= deleteBST(root->right,min);
            return root;
        }

    }
    else if(root->data >val){
        //  left part
        root->left=deleteBST(root->left,val);
        return root;
    }
    else{
        //  right part
        root->right=deleteBST(root->right,val);
        return root;
    }

}

int main()
{
    Node *root = nullptr;
}