
/**Alice is working on a project where she needs to build a complete binary tree from an array of integers. After constructing the tree, she wants to perform a post-order traversal to retrieve the node values in a specific order. 



Write a program that takes the number of nodes and the array as input and outputs the post-order traversal of the tree.

Input format :
The first line contains an integer n, representing the number of elements in the array.

The second line contains n space-separated integers, representing the values of the nodes in the binary tree.

Output format :
The output displays a single line containing n space-separated integers, which represent the postorder traversal of the binary tree constructed from the input array.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ n ≤ 15

1 ≤ array elements ≤ 100

Sample test cases :
Input 1 :
3
1 2 3
Output 1 :
2 3 1 
Input 2 :
5
1 2 3 4 5
Output 2 :
4 5 2 3 1  */


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


Node* create(vector<int>& arr, int index, int n) {
    if (index >= n) {
        return nullptr;
    }

    Node* root = new Node(arr[index]);

    // Recursively construct the left and right subtrees
    root->left = create(arr, 2 * index + 1, n);
    root->right = create(arr, 2 * index + 2, n);

    return root;
}

// F
void post(Node* root){
    if(root==nullptr){
        return;
    }
    post(root->left);
    post(root->right);
    cout<<root->data<<" ";
}

int main() {
    int n;
    cin >> n; // Number of elements in the array

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the values of the nodes
    }

    // Build the complete binary tree
    Node* root = create(arr, 0, n);

    // Perform the post-order traversal
    post(root);
    cout << endl;

    return 0;
}