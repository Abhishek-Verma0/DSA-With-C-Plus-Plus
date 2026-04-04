/*
===============================================================================
 Merge Sort - Explanation
===============================================================================

Merge Sort is a **Divide and Conquer** sorting algorithm.

 How it Works:
------------------
1. **Divide**:
   - Recursively split the array into two halves until each subarray has one element.

2. **Conquer**:
   - Merge the sorted subarrays back together in a sorted manner.

 Example:
-----------
Given: [4, 2, 5, 1, 3]

Step 1: Split until single elements:
   [4, 2, 5] and [1, 3]
   → [4, 2], [5], [1], [3]
   → [4], [2], [5], [1], [3]

Step 2: Merge sorted subarrays:
   → [2, 4], [5], [1, 3]
   → [2, 4, 5] and [1, 3]
   → Final sorted: [1, 2, 3, 4, 5]

⏱ Time Complexity:
--------------------
- Best Case: O(n log n)
- Average Case: O(n log n)
- Worst Case: O(n log n)

 Space Complexity:
---------------------
- O(n): Due to use of temporary array during merge step

 Merge Sort is a **stable sort**: It preserves the order of equal elements.

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Function to merge two sorted subarrays:
    - First subarray: arr[low ... mid]
    - Second subarray: arr[mid+1 ... high]
    Merges both into a single sorted subarray.
*/
void mergeSort(int arr[], int low, int mid, int high)
{
    vector<int> temp;    // Temporary array to store merged result
    int left = low;      // Starting index of left subarray
    int right = mid + 1; // Starting index of right subarray

    // Merge the two subarrays into temp[]
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]); // Take from left if smaller or equal
            left++;
        }
        else
        {
            temp.push_back(arr[right]); // Take from right if smaller
            right++;
        }
    }

    // Copy remaining elements from left subarray (if any)
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right subarray (if any)
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back into original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

/*
    Recursive Merge function:
    - Splits the array into two halves
    - Sorts each half
    - Merges them using mergeSort()
*/
void merge(int arr[], int low, int high)
{
    if (low >= high)
        return; // Base case: array with 1 or no element is already sorted

    int mid = (low + high) / 2; // Find middle index

    merge(arr, low, mid);      // Recursively sort left half
    merge(arr, mid + 1, high); // Recursively sort right half

    mergeSort(arr, low, mid, high); // Merge the two sorted halves
}

// Main function: Driver code
int main()
{
    int n=5;
    int arr[5] = {1, 8, 3, 7, 5};
    // Get size of the array from the user
    // cout << "Enter the size of the array: ";
    // cin >> n;

    // int arr[n]; // Declare array of size n (Note: use vector<int> for safer practice)

    // // Take array input from the user
    // cout << "Enter the elements of the array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // Call merge sort function
    merge(arr, 0, n - 1);

    // Print the sorted array
    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
