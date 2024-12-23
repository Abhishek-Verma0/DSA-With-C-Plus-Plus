//  here we will make tree from the input of level order of given binary treee
// level order means level by level like first we will make lvl 0 then other lvls

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};

void createTree(Node* &root){
    queue<Node*> q;
    cout<<"Enter the data for root "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){  
        Node* temp=q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left= new Node(leftdata);
            q.push(temp->left);
        }


        cout<<"Enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right= new Node(rightdata);
            q.push(temp->right);
        }
    }

}






//  printing in level order


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

    Node* root=nullptr;
    createTree(root);

    leveOrderTraversaal(root);
}