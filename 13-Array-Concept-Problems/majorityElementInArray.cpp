/*
===========================================
 MOORE'S VOTING ALGORITHM - EXPLAINED
===========================================

 Problem:
Find the majority element in an array (if it exists). A **majority element** appears **more than n/2 times** in the array.

 Moore’s Voting Algorithm:
A linear time, constant space algorithm to find the majority element.

 Working Principle:
It works on **cancellation**:
1. Assume the first element is the majority.
2. Use a `count` variable:
   - If the next element is the same, increment `count`.
   - If it’s different, decrement `count`.
   - If `count` becomes zero, pick the next element as a new candidate.
3. After one pass, the potential majority is stored.
4. Do another pass to confirm if it actually occurs more than n/2 times.

 Visualization:
Input: [2, 2, 1, 1, 2, 2, 2]

Pass 1 (finding candidate):
- el = 2, count = 1
- el = 2, count = 2
- el = 1, count = 1
- el = 1, count = 0 (reset)
- el = 2, count = 1
- el = 2, count = 2
- el = 2, count = 3 → candidate is 2

Pass 2 (verifying):
- Count of 2 = 5 > n/2 → Majority element is 2

 Time Complexity: O(n)
 Space Complexity: O(1)

 Use Cases:
 Finding dominant elements in surveys, voting, polling data
 Frequency-based predictions
 Preprocessing in machine learning or data filtering
*/

// Include all standard libraries (used in competitive programming)
#include <bits/stdc++.h>
using namespace std;

// Function to implement Moore's Voting Algorithm
void moore(vector<int> &arr, int n)
{
    int count = 0; // To keep track of current candidate count
    int el;        // To store the potential majority element
    int cnt = 0;   // To count actual occurrences of candidate

    // Step 1: Find a candidate for majority element
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            el = arr[i]; // Set current element as candidate
            count = 1;
        }
        else if (arr[i] == el)
        {
            count++; // Same as candidate → increment count
        }
        else
        {
            count--; // Different → cancel out
        }
    }

    // Step 2: Verify the candidate (is it really majority?)
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el) // Corrected from assignment (=) to comparison (==)
            cnt++;
    }

    // Step 3: Check if count > n/2
    if (cnt > (n / 2))
    {
        cout << "Majority element is :: " << el << endl;
    }
    else
    {
        cout << "No majority element" << endl;
    }
}

// Main function
int main()
{
    int n;

    // Ask user for array size
    cout << "Enter the size of an array :: ";
    cin >> n;

    vector<int> arr(n);

    // Take array input
    cout << "Enter the elements for the array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    /*
     Finding the majority element in the array.
     A majority element is one that appears more than n/2 times.
     We use the efficient Moore's Voting Algorithm for this.
    */
    moore(arr, n);

    return 0;
}
