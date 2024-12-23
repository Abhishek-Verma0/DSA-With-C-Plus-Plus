/**Problem Statement



Emma is a data analyst working on a project where she needs to maintain a max heap of scores collected from various sports events. After collecting the scores, she wants to build the max heap and calculate the sum of the highest and lowest scores in the heap.



Your task is to help Emma by implementing a program that builds the max heap from the input scores and computes the required sum.

Input format :
The first line contains an integer N, representing the number of scores Emma will input.

The second line consists of N space-separated integers, representing the individual scores.

Output format :
The first line displays N space-separated integers, representing the max heap in a single line, with scores separated by spaces.

The second line displays an integer representing the sum of the highest score (root of the max heap) and the lowest score (last element of the heap).



Refer to the sample output for exact format specifications.

Code constraints :
1 ≤ N ≤ 20

1 ≤ scores ≤ 1000

Sample test cases :
Input 1 :
4
6 10 8 5
Output 1 :
10 6 8 5 
15
Input 2 :
6
18 39 46 38 76 89
Output 2 :
89 46 76 18 38 39 
128 */

/**header and footer one  */


//header
#include <iostream>
using namespace std;




// // You are using GCC
// // void swap(int arr[], int a, int b) {
// //     //Type your code here
// // }

// void maxHeapify(int arr[], int n, int i) {
//     //Type your code here
//     int largest=i;
//     int left=2*i;
//     int right=2*i + 1;
//     if(left < n && arr[largest]< arr[left]){
//         largest=left;
//     }
//      if(right <n && arr[largest] <arr[right]){
//          largest=right;
//      }
     
//      if(largest!=i){
//          swap(arr[largest],arr[i]);
//          maxHeapify(arr,n,largest);
//      }
// }

// void buildMaxHeap(int arr[], int n) {
//     //Type your code here
//     for (int i = n / 2; i >= 1; --i) {
//         maxHeapify(arr, n, i);
//     }
// }

// void insertIntoMaxHeap(int arr[], int &n, int value) {
//     //Type your code here
//     n++;
//     int index=n;
//     arr[index]=value;
//     while(index>1){
//         int parent= index/2;
//         if(arr[parent]<arr[index]){
//             swap(arr[parent],arr[index]);
//             index=parent;
//         }
//         else{
//             return;
//         }
//     }
// }

// void printMaxHeap(int arr[], int n) {
//     //Type your code here
//     for(int i=1;i<=n;i++){
//         cout<<arr[i]<<" ";
//     }
//         cout<<endl;
// }


void maxHeapify(int arr[], int n, int i) {
    int largest = i;               // Assume the largest is the root
    int left = 2 * i + 1;          // Left child index (0-based)
    int right = 2 * i + 2;         // Right child index (0-based)

    // Check if the left child exists and is larger than the root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Check if the right child exists and is larger than the current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);  // Recursively heapify the affected subtree
    }
}

// Build Max-Heap for 0-based index
void buildMaxHeap(int arr[], int n) {
    // Start from the last non-leaf node and call maxHeapify on each node
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapify(arr, n, i);
    }
}

// Insert function for 0-based index
void insertIntoMaxHeap(int arr[], int &n, int value) {
    // Increment the size of the heap
    n++;

    // Insert the value at the end of the array (heap)
    arr[n - 1] = value;

    // Move the inserted element to its correct position to maintain the heap property
    int index = n - 1;
    while (index > 0 && arr[index] > arr[(index - 1) / 2]) {
        swap(arr[index], arr[(index - 1) / 2]);  // Swap with the parent if the current element is larger
        index = (index - 1) / 2;  // Move to the parent
    }
}

// Print function for 0-based index
void printMaxHeap(int arr[], int n) {
    // Print each element of the heap array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//  footer

int main() {
    int arr[100];
    int n = 0;
    int num_elements;
    cin >> num_elements;
    for (int i = 0; i < num_elements; i++) {
        int value;
        cin >> value;
        insertIntoMaxHeap(arr, n, value);
    }
    buildMaxHeap(arr, n);
    printMaxHeap(arr, n);
    if (n > 0) {
        int sum = arr[0] + arr[n - 1]; 
        cout << sum;
    } else {
        cout << "Heap is empty";
    }
    return 0;
}