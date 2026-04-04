#include <bits/stdc++.h> // Include all standard libraries
using namespace std;

// Function to find the smallest and second smallest elements in the array
void smallSecsmall(vector<int> &arr, int n)
{
    int sm = INT_MAX;    // Initialize smallest to maximum possible integer
    int Secsm = INT_MAX; // Initialize second smallest similarly

    // Loop through each element of the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < sm)
        {
            // If current element is less than smallest so far
            // Update second smallest first, then smallest
            Secsm = sm;
            sm = arr[i];
        }
        else if (arr[i] < Secsm && arr[i] != sm)
        {
            // If current element is not equal to the smallest
            // and less than second smallest, update second smallest
            Secsm = arr[i];
        }
    }

    // Output the smallest and second smallest elements
    cout << "Smallest element is :: " << sm << endl;
    cout << "Second Smallest element is :: " << Secsm << endl;

    // Optional (Not in  code):  might want to check if Secsm is still INT_MAX,
    // which would mean a second smallest doesn't exist
}

// Main function to take input and call the logic function
int main()
{

    int n; // Variable to store size of the array

    // Ask user for size of the array
    cout << "Enter the size Of array ";
    cin >> n;

    // Declare a vector of size 'n'
    vector<int> arr(n);

    // Take array elements as input from user
    cout << "Enter the elements for the array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call function to find and display smallest and second smallest elements
    smallSecsmall(arr, n);
}
