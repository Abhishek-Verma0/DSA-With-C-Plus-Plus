#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *createNode(Node *head, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *delHead(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

//  ************function to delete kth node

Node *delKth(Node *head, int pos, int &size)
{
    if (pos < 1 || pos > size)
    {
        cout << "Invalid position ";
        return head;
    }

    if (pos == 1)
    {
        size--;
        return delHead(head);
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }
    if (temp->next == nullptr)
    {
        return head;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    size--;
    return head;
}

void display(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *head = nullptr;

    int n, value, pos;
    cout << "Enter the number of nodes you want in the linked list :: ";
    cin >> n;
    cout << "Enter the values for the each node :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        head = createNode(head, value);
    }

    display(head);

    cout<<"Enter the desired postion to delete the node ---";
    cin>>pos;
    head=delKth(head,pos,n);
    cout<<"Printing the node after deleting the node at desired postion  ::: ";
    display(head);
}