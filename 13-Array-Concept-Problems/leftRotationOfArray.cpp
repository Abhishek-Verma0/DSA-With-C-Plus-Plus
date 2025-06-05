// -----------------------------------------------
// Program to Rotate an Array to the Left by 'm' Positions using Reversal Algorithm
// -----------------------------------------------
//
//  Concept:
// To rotate an array to the left by `m` positions, we can use the Reversal Algorithm.
// The idea is to reverse parts of the array to achieve rotation **in-place** (without extra space).
//
//  Steps to rotate left by m:
// 1. Reverse the first `m` elements
// 2. Reverse the remaining `n - m` elements
// 3. Reverse the whole array
//
//  Time Complexity: O(n)
//  Space Complexity: O(1) (in-place)
//
// Example:
// Original Array:   [1, 2, 3, 4, 5, 6, 7]
// Left Rotate by 2:
// Step 1 (reverse first 2):        [2, 1, 3, 4, 5, 6, 7]
// Step 2 (reverse last 5):         [2, 1, 7, 6, 5, 4, 3]
// Step 3 (reverse whole array):    [3, 4, 5, 6, 7, 1, 2]
//
//  Result is the array rotated left by 2 places
// -----------------------------------------------

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

// Function to perform left rotation using reversal algorithm
void leftRot(vector<int> &arr, int &left, int &n)
{
    int m = left % n;       
    reverse(arr, 0, m - 1); //  Reverse first 'm' elements
    reverse(arr, m, n - 1); //  Reverse the remaining elements
    reverse(arr, 0, n - 1); //  Reverse the entire array
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

    cout << "Enter how many times you want to rotate the array to left :: ";
    int left;
    cin >> left;

    // Call the rotation function
    leftRot(arr, left, n);

    // Output the rotated array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
