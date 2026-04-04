#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}


// **************************Function to find all non-common elements between two linked lists*******************************
//************************************************************************************************************************ */
void findAllNonCommon(Node* head1, Node* head2) {
    Node* temp = head1;

    cout << "Non-common elements from the first list: ";
    // Traverse the first list and check if each element is not in the second list
    while (temp != nullptr) {
        if (!isPresentInList(head2, temp->data)) {
            cout << temp->data << " ";  // Print non-common element
        }
        temp = temp->next;
    }

    cout << endl;

    temp = head2;
    cout << "Non-common elements from the second list: ";
    // Traverse the second list and check if each element is not in the first list
    while (temp != nullptr) {
        if (!isPresentInList(head1, temp->data)) {
            cout << temp->data << " ";  // Print non-common element
        }
        temp = temp->next;
    }

    cout << endl;
}

// Function to check if an element is present in the second list
bool isPresentInList(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == value) {
            return true;  // Element found
        }
        temp = temp->next;
    }
    return false;  // Element not found
}

int main() {
    Node* head = nullptr;
    Node* head1 = nullptr;
    int n, m, num, num1;
    cout << "Enter the number of nodes for the first linked list  :: ";
    cin >> n;
    cout << "Enter the values  for the linked list 1 :: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        head = createNode(head, num);
    }
    cout << endl;
    cout << "Enter the number of nodes for the second linked list :: ";
    cin >> m;
    cout << "Enter the values for the second linked list  :: ";
    for (int i = 0; i < m; i++) {
        cin >> num1;
        head1 = createNode(head1, num1);
    }

    cout << endl;
    cout << "Printing the first linked list :: ";
    printList(head);
    cout << endl;
    cout << "Printing the second linked list :: ";
    printList(head1);

    // Find and print all non-common elements
    findAllNonCommon(head, head1);

    return 0;
}
