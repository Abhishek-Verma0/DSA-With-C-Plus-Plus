// Here we are inserting the element in the linked list at user given position




#include <iostream>
using namespace std;
  // Define structure for a Node in the linked list 
struct Node
{
    int data;   // this will hold the value of the Node
    Node *next;  // pointer to the next node in the list 
};


//function to insert at the specified place  in the linked list 
Node *insert(Node *head, int pos, int data, int &size)
{
    // checking whether given position is valid or not  means between 1 and size + 1
    if (pos < 1 || pos > size + 1)
    {
        cout << "Invalid position!" << endl;
        return head;  // returning the original list if the position is valid 
    }
// creating the new node 
    Node *newNode = new Node();  // dynamic allocation of memory to the new node 
    newNode->data = data;  // data value to the new node 
    newNode->next = nullptr; // at initial stage , the new node's next is set to the  nullptr
// if we need to insert at the head means position 1
    if (pos == 1)
    {
        newNode->next = head;  // the new node's next is pointing to the current head
        size++;  //Increase the sizee of the list since the new node is added
        return newNode;  // return the new node as the new head of the list 
    }
// inserting other than head place 
    Node *curr = head;  // start  from  the head of the list 

    // traversing the list to find the position to insert the  node 
    for (int i = 1; i < pos - 1 && curr != nullptr; i++)
    {
        curr = curr->next; // moving to the next node in each iteration
    }
// here curr points to the  node just before the insertion point 
    newNode->next = curr->next;  //  link the new  node's  next to the node after curr 
    curr->next = newNode; // link curr's next to the new node and inserting it in the list 
    size++;  // increase the size of the list after insertion of new node 

    return head;  // original head is being returned as head is not changed   unless we insert at the head of the given linked list 
}
  //  function  to print the nodes of linked list 
void printList(Node *head)
{
    Node *curr = head;  // starting from the head of the linked list 
    while (curr != nullptr)
    {
        cout << curr->data << " ";  // printing the data of the current node 
        curr = curr->next;  //  moving to the next node 
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;  // initialsing the empty linked list 
    int size = 0;  // size of the linked list is initallly initalised to zero 
    int n, data, pos;
// take input from the user how many nodes he or she want in the linked list 
    cout << "Enter the number of nodes for the linked list: ";
    cin >> n;   
//  take input for the inital elements of the  linked list 
    cout << "Enter the elements of the linked list: ";
    for (int i = 0; i < n; i++)
    {
        cin >> data;  // input data value for the each new node
        head = insert(head, size + 1, data, size);  // insert each node at the end of list that is position -> size+1  which is last position 
    }

    cout << "Current Linked List: ";
    //  print the linked list before inserting the element at the certain position 
    printList(head);

    cout << "Enter the data to insert: ";
    cin >> data;  // input of data to be inserted 
    cout << "Enter the position to insert the data: ";
    cin >> pos;  // input of the position where the node is to inserted 

    head = insert(head, pos, data, size);  // calling insert function to inserting the node at certain position 

    cout << "Updated Linked List: ";
    printList(head);  // this prints the list after insertion of the new node at the specifiedn place by user 

    return 0;  // this exit the program 
}
