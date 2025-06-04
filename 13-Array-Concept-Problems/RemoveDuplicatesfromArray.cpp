#include<bits/stdc++.h>
using namespace std;

void remDup(vector<int>&arr,int n){
    set<int> noDup;  // set stores only unique elements 
    for (int i = 0; i < n;i++){
        noDup.insert(arr[i]);
    }

    cout << "Displaying unique elements :: ";
    for( auto &i : noDup){
        cout << i << " ";
    }
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

    // Call function
    remDup(arr, n);
}