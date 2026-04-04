/*
===============================
 DUTCH NATIONAL FLAG ALGORITHM
===============================

 Problem:
Given an array consisting of only 0s, 1s, and 2s (unsorted),
sort it in linear time without using any sorting algorithm.

 Why it's called "Dutch National Flag"?
It was proposed by Edsger Dijkstra and resembles the flag of the Netherlands, which has three colors: red, white, and blue.
We associate:
    - 0 → Red
    - 1 → White
    - 2 → Blue

 Visualization:
Imagine 3 partitions in the array:
    [0, 0, 0]   [1, 1]   [2, 2, 2]
     low zone   mid zone  high zone

We maintain three pointers:
    - low   → boundary for 0s (starting from index 0)
    - mid   → current element under consideration
    - high  → boundary for 2s (starting from the last index)

We iterate through the array and:
    - If arr[mid] == 0: Swap with arr[low], increment both low and mid
    - If arr[mid] == 1: Move mid ahead
    - If arr[mid] == 2: Swap with arr[high], decrement high

 Advantages:
 In-place algorithm (no extra space)
 Linear time complexity → O(n)
 Simple and efficient

 Applications:
- Sorting arrays with limited distinct elements (e.g., 3-category classification)
- Pre-processing for counting problems
- Partitioning algorithms in computer vision, color-based sorting, etc.
*/

// Include all standard C++ headers
#include <bits/stdc++.h>
using namespace std;

// Function to sort array using Dutch National Flag Algorithm
void dutch(vector<int> &arr, int n)
{
    int low = 0;      // Initialize low pointer
    int mid = 0;      // Initialize mid pointer
    int high = n - 1; // Initialize high pointer

    // Traverse the array until mid crosses high
    while (mid <= high)
    {
        // Case 1: Current element is 0
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]); // Swap it with element at 'low'
            low++;                    // Increment low
            mid++;                    // Move mid to next
        }
        // Case 2: Current element is 1
        else if (arr[mid] == 1)
        {
            mid++; // Just move mid ahead
        }
        // Case 3: Current element is 2
        else if (arr[mid] == 2)
        {
            swap(arr[mid], arr[high]); // Swap it with element at 'high'
            high--;                    // Decrement high (do not move mid here!)
        }
    }

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    int n;

    // Ask user for size of the array
    cout << "Enter the size of the array: ";
    cin >> n;

    // Declare a vector of size n
    vector<int> arr(n);

    // Ask user to input elements (only 0s, 1s, or 2s)
    cout << "Enter the elements of the array (only 0, 1, or 2): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Display the sorted array
    cout << "Array after sorting using Dutch National Flag Algorithm: ";
    dutch(arr, n);

    return 0;
}
