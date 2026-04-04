#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

// Function to find the largest and second largest elements in the array
void largSeclarg(vector<int> &arr, int n)
{
    int larg = INT_MIN;    // Initialize largest as smallest possible integer
    int secLarg = INT_MIN; // Initialize second largest similarly

    // Loop through each element in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > larg)
        {
            // If current element is greater than largest found so far,
            // update second largest first, then update largest
            secLarg = larg;
            larg = arr[i];
        }
        else if (arr[i] > secLarg && arr[i] != larg)
        {
            // If current element is not equal to the largest
            // and is greater than current second largest, update second largest
            secLarg = arr[i];
        }
    }

    // Output the largest and second largest elements
    cout << "Largest element is  :: " << larg << endl;
    cout << "Second Largest element is  :: " << secLarg << endl;
}

int main()
{
    int n; // Variable to store size of array

    // Prompt user to enter size of the array
    cout << "Enter size of array :: ";
    cin >> n;

    // Declare a vector of size n
    vector<int> arr(n);

    // Prompt user to input elements of the array
    cout << "Enter elements for the array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call function to find and display largest and second largest elements
    largSeclarg(arr, n);
}
