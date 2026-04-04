// ------------------------------------------------------------
// Program to Rotate an Array to the Right by 'm' Positions using Reversal Algorithm
// ------------------------------------------------------------
//
//  Concept:
// To rotate an array to the **right** by `m` positions efficiently,
// we use the **Reversal Algorithm**. It performs the rotation in-place (no extra memory).
//
//  Steps to rotate right by m:
// 1. Reverse the entire array
// 2. Reverse the first `m` elements
// 3. Reverse the remaining `n - m` elements
//
//  Time Complexity: O(n)
//  Space Complexity: O(1)
//
// Example:
// Original Array:   [1, 2, 3, 4, 5, 6, 7]
// Right Rotate by 2:
// Step 1 (reverse whole):         [7, 6, 5, 4, 3, 2, 1]
// Step 2 (reverse first 2):       [6, 7, 5, 4, 3, 2, 1]
// Step 3 (reverse last 5):        [6, 7, 1, 2, 3, 4, 5]
//
//  Result is the array rotated right by 2 places
// ------------------------------------------------------------

#include <bits/stdc++.h> 
using namespace std;

// Function to reverse elements in the array between two indices: start and end
void reverse(vector<int> &arr, int start, int end)
{
    while (start < end)
    {
        swap(arr[start++], arr[end--]);
    }
}

// Function to perform right rotation using the reversal algorithm
void rightRot(vector<int> &arr, int right, int n)
{
    int m = right % n;      // gives number of rotation to avoid unnecessary rotation if given rotation brings to original array 
    reverse(arr, 0, n - 1); //  Reverse the whole array
    reverse(arr, 0, m - 1); // Reverse the first 'm' elements
    reverse(arr, m, n - 1); //  Reverse the rest of the array
}

int main()
{
    int n; // Size of the array
    cout << "Enter the size of array :: ";
    cin >> n;

    vector<int> arr(n); // Declare a vector of size n

    cout << "Enter the elements for the array :: ";
    // Input array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter how many times you want to rotate the array to right :: ";
    int right;
    cin >> right;

    // Call the right rotation function
    rightRot(arr, right, n);

    // Output the rotated array
    cout << "Rotated array :: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
