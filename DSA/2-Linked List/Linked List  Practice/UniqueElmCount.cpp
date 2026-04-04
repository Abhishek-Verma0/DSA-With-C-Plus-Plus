/**In a customer service system, interactions between users and the service team are recorded in a log. Each interaction is represented by a unique identifier. Your task is to analyze the log and determine the number of unique user interactions.



Utilize a two-way linked list to solve the program.



Company Tags: Amazon

Input format :
The first line of input consists of an integer N, representing the number of interactions.

This is followed by N lines of strings, each representing an interaction identifier.

Output format :
The output prints a single line containing the number of unique user interactions.



Refer to the sample output for formatting specifications.

Code constraints :
1 ≤ N ≤ 20﻿

Sample test cases :
Input 1 :
3
ABC123
DEF456
GHI789
Output 1 :
Number of unique user interactions: 3
Input 2 :
5
ABC123
DEF456
ABC123
JKL987
DEF456
Output 2 :
Number of unique user interactions: 3
Input 3 :
2
XYZ789
XYZ789
Output 3 :
Number of unique user interactions: 1 */


// You are using GCC
#include <iostream>
#include <string>
using namespace std;
struct Node {
    string data;
    Node* prev;
    Node* next;
};

void insertAtBeginning(Node** head, const std::string& newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = *head;

    if (*head != nullptr)
        (*head)->prev = newNode;

    *head = newNode;
}
int countUniqueInteractions(Node* head) {
    Node* curr=head;
    
    int count=0;
while (curr != nullptr) {
        bool isUnique = true;
     Node* cu = curr->next;

        while (cu != nullptr) {
            if (curr->data == cu->data) {
                isUnique = false; 
                break;
            }
            cu = cu->next;
        }

        if (isUnique) {
            count++; 
        }
        curr = curr->next; 
    }

    return count;
}

    


int main() {
    Node* head = nullptr;
    int n;
    string data;

    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> data;
        insertAtBeginning(&head, data);
    }

    int uniqueInteractions = countUniqueInteractions(head);

    cout << "Number of unique user interactions: " << uniqueInteractions << std::endl;

    return 0;
}