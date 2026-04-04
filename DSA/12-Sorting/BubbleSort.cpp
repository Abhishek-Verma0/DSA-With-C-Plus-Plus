#include <bits/stdc++.h>
using namespace std;

/*
=======================================
📌 Bubble Sort Overview

Bubble Sort is a simple sorting algorithm that works by repeatedly
swapping adjacent elements if they are in the wrong order.
It "bubbles up" the largest unsorted element to the end of the array
in each pass, just like a bubble rising to the surface.

 How It Works:
- Compare each pair of adjacent elements.
- Swap them if they’re in the wrong order (larger before smaller).
- After each pass, the largest unsorted element is moved to its correct position.
- Repeat this for all elements (n-1 passes). 

⏱ Time Complexity:
- Best Case:    O(n)       → when the array is already sorted (with optimization)
- Average Case: O(n^2)
- Worst Case:   O(n^2)     → when the array is reverse sorted
- Space:        O(1)       → in-place sorting

 Stable Sort: Yes
=======================================
*/

void bubble(int arr[], int n)
{
    // Outer loop for number of passes
    // After each pass, one largest element settles at its correct position at the end
    for (int i = 0; i < n - 1; i++)
    {
        // Inner loop goes from start to the last unsorted element
        for (int j = 0; j < n - i - 1; j++)
        {
            // Compare current element with the next one
            if (arr[j] > arr[j + 1])
            {
                // Swap if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
        // After each iteration of this loop, the i-th largest element is at position n - i - 1
    }
}

int main()
{
    int n;
    cout << "Enter the size of an array :: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call bubble sort to sort the array
    bubble(arr, n);

    // Print the sorted array
    cout << "\nAfter sorting array :: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
