
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

//  in level order traversal we traverse  the tree level by level means every node at  the same level is visited first


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



int main()
{
    Node *root = nullptr;
//     creating tree
    root = createTree(root);


    //  level order
    cout<<"Level order "<<endl;
    leveOrderTraversaal(root);

}