#include <bits/stdc++.h> // Includes all standard C++ libraries
using namespace std;

/*
    QUICK SORT ALGORITHM
    ---------------------
    Quick Sort is a **divide and conquer** algorithm.

    Working:
    - Pick an element as a "pivot" (in this implementation, we use the first element).
    - Partition the array so that:
        * Elements less than or equal to the pivot come before it.
        * Elements greater than the pivot come after it.
    - Recursively apply the same logic to the left and right subarrays.

    Time Complexity:
    - Best Case: O(n log n)
    - Average Case: O(n log n)
    - Worst Case: O(n^2) [occurs when the array is already sorted or reverse sorted and pivot choice is poor]

    Space Complexity: O(log n) due to recursion stack
*/

// Partition function to place the pivot at correct position and return its index
int part(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choosing the first element as pivot
    int i = low;          // Pointer from left
    int j = high;         // Pointer from right

    // Loop until the two pointers meet
    while (i < j)
    {
        // Increment i while elements are <= pivot and within bounds
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        // Decrement j while elements are > pivot and within bounds
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        // Swap elements at i and j if i < j
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // Swap pivot with the element at j to put pivot at its correct place
    swap(arr[low], arr[j]);

    // Return the index of the pivot after partition
    return j;
}

// QuickSort function to recursively sort the subarrays
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition the array and get the pivot index
        int prevIdx = part(arr, low, high);

        // Recursively sort the left subarray
        quickSort(arr, low, prevIdx - 1);

        // Recursively sort the right subarray
        quickSort(arr, prevIdx + 1, high);
    }
}

int main()
{
    int n;
    cin >> n; // Input the number of elements

    int arr[n]; // Declare array of size n

    // Input the elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call the quickSort function to sort the entire array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
