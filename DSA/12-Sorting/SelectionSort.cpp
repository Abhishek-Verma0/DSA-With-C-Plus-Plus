/*
    ===================== Selection Sort =====================

    What is Selection Sort?
    ------------------------
    Selection Sort is a simple comparison-based sorting algorithm.
    It divides the array into two parts: the sorted part and the unsorted part.

    How it Works:
    --------------
    - Start from the first element of the array.
    - Find the smallest element in the unsorted part of the array.
    - Swap it with the element at the beginning of the unsorted part.
    - Move the boundary of the sorted part one step to the right.
    - Repeat until the entire array is sorted.

    Time Complexity:
    ----------------
    - Best Case:    O(n²)
    - Average Case: O(n²)
    - Worst Case:   O(n²)

    Space Complexity:
    -----------------
    - O(1) — In-place sorting, requires no extra space.

    Notes:
    ------
    - It is not a stable sort.
    - It is an in-place sorting algorithm.
    - Useful for small datasets or when memory write is more costly than read.

*/
#include<bits/stdc++.h>
using namespace std;
void selection(int arr[], int n)
{
    // Loop through each element of the array
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the current element is the minimum
        int min = i;

        // Find the index of the smallest element in the remaining unsorted array
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j; // Update index of minimum element
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (min != i)
        {
            swap(arr[i], arr[min]);
        }
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

    //  calling selection sort

    selection(arr, n);
    // Print the sorted array
    cout << "\nAfter sorting array :: \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
