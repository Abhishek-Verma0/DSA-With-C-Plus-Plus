/*
Insertion Sort Algorithm

Definition:
Insertion sort is a simple sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

How it works:
1. Assume that the first element is already sorted.
2. Take the next element and compare it with the elements in the sorted portion.
3. Shift all larger elements one position to the right.
4. Insert the current element into its correct position.
5. Repeat until the array is fully sorted.

Time Complexity:
- Best Case (Already Sorted): O(n)
- Average Case: O(n^2)
- Worst Case (Reversely Sorted): O(n^2)
- Space Complexity: O(1) – In-place sort
- Stable: Yes

*/

#include <iostream> // For input and output
using namespace std;

// Insertion sort function
void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;

        // Shift elements of arr[0..i-1], that are greater than key
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Shift element to the right
            j--;
        }
        arr[j + 1] = key; // Place key in its correct position
    }
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n]; // You can use vector<int> arr(n); for better practice

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Calling the insertion sort function
    insertion(arr, n);

    // Display the sorted array
    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
