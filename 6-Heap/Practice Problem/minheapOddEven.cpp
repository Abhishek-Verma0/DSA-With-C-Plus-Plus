/**Problem Statement



Aiden is working on organizing his collection of unique integers, which represent the number of books he has in different categories. He wants to create a min heap out of these integers so that he can quickly access the category with the smallest number of books. Additionally, Aiden is curious about the sum of all even and odd numbers in his collection.



Write a program that builds a min heap from Aiden's collection of numbers, displays the min heap, and calculates the sum of even and odd numbers separately.

Input format :
The first line contains an integer representing n representing the number of integers in Aiden's collection.

The second line contains n space-separated integers representing the number of books in each category.

Output format :
The first line displays the min heap structure, where the smallest number of books is at the root.

The second line displays the sum of all even numbers in the collection.

The third line displays the sum of all odd numbers in the collection.



Refer to the sample output for formatting specifications.

Code constraints :
The given test cases will fall under the following constraints:

1 ≤ n ≤ 10

1 ≤ no.of. books ≤ 100

Sample test cases :
Input 1 :
5
2 4 1 5 9
Output 1 :
Min Heap: 1 4 2 5 9 
Sum of even elements: 6
Sum of odd elements: 15 */


// header

#include <iostream>
using namespace std;

// You are using GCC

void minHeapify(int heap[], int size, int i) {
    int smallest = i;  // Start by assuming the current node is the smallest
    int left = 2 * i + 1;  // Left child index (for 0-based indexing)
    int right = 2 * i + 2; // Right child index (for 0-based indexing)

    // Check if the left child exists and is smaller than the current smallest
    if (left < size && heap[left] < heap[smallest]) {
        smallest = left;
    }

    // Check if the right child exists and is smaller than the current smallest
    if (right < size && heap[right] < heap[smallest]) {
        smallest = right;
    }

    // If the smallest is not the current node, swap and heapify again
    if (smallest != i) {
        swap(heap[smallest], heap[i]);
        minHeapify(heap, size, smallest);  // Recursively heapify the affected subtree
    }
}

void buildMinHeap(int heap[], int size) {
    // Start from the last non-leaf node and move upwards
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

void insertElement(int heap[], int &size, int value, int &sumEven, int &sumOdd) {
    // Increment the size of the heap and add the value at the last position
    heap[size] = value;  // Insert at the end of the heap
    size++;

    // Update the sum of even and odd elements
    if (value % 2 == 0) {
        sumEven += value;
    } else {
        sumOdd += value;
    }

    // Bubble up the element to maintain the Min-Heap property
    int i = size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            swap(heap[parent], heap[i]);
            i = parent;
        } else {
            break;
        }
    }
}

void displayMinHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
// footer
int main() {
    int n;
    cin >> n;
    int heap[n];
    int size = 0;
    int sumEven = 0, sumOdd = 0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertElement(heap, size, value, sumEven, sumOdd);
    }
    buildMinHeap(heap, size);
    cout << "Min Heap: ";
    displayMinHeap(heap, size);
    cout << "Sum of even elements: " << sumEven << endl;
    cout << "Sum of odd elements: " << sumOdd;
    return 0;
}