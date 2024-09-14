// // this code shows the implementation of the linked list and how we can track and delete the nodes which are at the even position 
// // similar code will also be for the deleting the nodes at odd position in the linked list 


// #include <iostream>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;
// };

// void insertNode(Node **head, int data)
// {
//     Node *newNode = new Node();
//     newNode->data = data;
//     newNode->next = nullptr;

//     if (*head == nullptr)
//     {
//         *head = newNode;
//     }
//     else
//     {
//         Node *temp = *head;
//         while (temp->next != nullptr)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }


// //  function to delete the nodes at even positions
// void deleteEvenPositionNodes(Node **head)
// {
//     // checks whether the linked list is empty or it ony contains one node 
//     if (*head == nullptr || (*head)->next == nullptr)
//     {
//         return;
//     }
//     // Initialize pointers and position counter
//     Node *temp = *head;   // Start from the head of the list
//     Node *prev = nullptr; // Previous node pointer, initially set to nullptr
//     int count = 1; // position counter starting from 1
//     // traverse the linked list 
//     while (temp != nullptr)
//     {
//         if (count % 2 == 0)
//         { // if position is even then delete the current node 
//             prev->next = temp->next;  // this skips the current node 
//             delete temp;  // this frees the memory for the current node 
//             temp = prev->next; //  moves to the next node
//         }
//         else
//         { // is postion is not even 
//             prev = temp;  //move prev to the current node 
//             temp = temp->next; //move temp to the next node 
//         }
//         count++;
//     }
// }
// void displayLinkedList(Node *head)
// {
//     Node *temp = head;
//     while (temp != nullptr)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main()
// {
//     Node *head = nullptr;
//     int size;

//     cin >> size;

//     for (int i = 0; i < size; i++)
//     {
//         int value;
//         cin >> value;
//         insertNode(&head, value);
//     }

//     cout << "Original Linked List: ";
//     displayLinkedList(head);

//     deleteEvenPositionNodes(&head);

//     cout << "Final Linked List: ";
//     displayLinkedList(head);

//     Node *temp = head;
//     while (head != nullptr)
//     {
//         head = head->next;
//         delete temp;
//         temp = head;
//     }

//     return 0;
// }




// according to neocolab

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of the linked list
void insertNode(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to check if a value exists in the second list
int valueExists(struct Node *second, int value)
{
    struct Node *temp = second;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return 1; // Value found
        }
        temp = temp->next;
    }
    return 0; // Value not found
}

// Function to delete nodes from list1 that also exist in list2
void deleteNodesInSecondList(struct Node **head1, struct Node *head2)
{
    struct Node *temp = *head1;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (valueExists(head2, temp->data))
        {
            // Node found in second list, delete it
            if (prev == NULL)
            {
                *head1 = temp->next;
                free(temp);
                temp = *head1;
            }
            else
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }
        }
        else
        {
            // Move to the next node
            prev = temp;
            temp = temp->next;
        }
    }
}

// Function to display the linked list
void displayLinkedList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete all nodes in the linked list
void deleteLinkedList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to check if the linked list is empty
int isListEmpty(struct Node *head)
{
    return head == NULL;
}

// Main function
int main()
{
    struct Node *first = NULL;
    struct Node *second = NULL;
    int size1, size2;

    // Input for list1
    scanf("%d", &size1);
    for (int i = 0; i < size1; i++)
    {
        int value;
        scanf("%d", &value);
        insertNode(&first, value);
    }

    // Input for list2
    scanf("%d", &size2);
    for (int i = 0; i < size2; i++)
    {
        int value;
        scanf("%d", &value);
        insertNode(&second, value);
    }

    // Display list1 before deletion
    printf("Before deletion: ");
    displayLinkedList(first);

    // Delete common nodes from list1
    deleteNodesInSecondList(&first, second);

    // Display list1 after deletion
    printf("After deletion: ");
    if (isListEmpty(first))
    {
        printf("Elements in both lists are same\n");
    }
    else
    {
        displayLinkedList(first);
    }

    // Free allocated memory
    deleteLinkedList(first);
    deleteLinkedList(second);

    return 0;
}
