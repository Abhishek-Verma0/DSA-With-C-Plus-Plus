/*
    Concept & Approach:
    -------------------
    The goal is to move all zero elements in the array to the end while maintaining
    the relative order of non-zero elements.

    Approach:
    - We traverse the array and for every non-zero element, we place it at the index `idx` and increment `idx`.
    - After placing all non-zero elements, we fill the rest of the array from `idx` to end with zeros.
    - This operation is done in-place with O(n) time complexity and O(1) space complexity.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to move all zeros to the end of the array
void toEnd(vector<int> &arr, int n)
{
    int idx = 0;

    // Move non-zero elements forward
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[idx++] = arr[i];
        }
    }

    // Fill remaining positions with zero
    for (int i = idx; i < n; i++)
    {
        arr[i] = 0;
    }
}

int main()
{
    int n;
    cout << "Enter the size of an array :: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements for the array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    toEnd(arr, n);

    cout << "After moving zeros to end :: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
