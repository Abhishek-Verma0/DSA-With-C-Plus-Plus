
/*
----------------------------------------------------------
Concept: Union of Two Arrays (Without Duplicates)
----------------------------------------------------------

Problem:
Given two arrays, find their union – i.e., combine both arrays into one, but without duplicates.
The union should be sorted in ascending order.

Approach:
1. Sort both input arrays (if they are not already sorted).
2. Use the Two Pointer Technique to traverse both arrays simultaneously.
3. Use a `set<int>` to store elements – which automatically removes duplicates and keeps the elements sorted.
4. Insert elements from both arrays into the set as we traverse them.

Why `set`?
- Automatically handles duplicates.
- Maintains ascending order (sorted).

----------------------------------------------------------
*/


#include <bits/stdc++.h>
using namespace std;

void twoUnion(vector<int> &arr, vector<int> &vec, int n, int m)
{
    set<int> temp; // Set to store unique and sorted union elements

    //  Sort both arrays to prepare for two-pointer traversal
    sort(arr.begin(), arr.end());
    sort(vec.begin(), vec.end());

    int i = 0; // Pointer for the first array
    int j = 0; // Pointer for the second array

    // Traverse both arrays using two pointers
    while (i < n && j < m)
    {
        if (arr[i] < vec[j])
        {
            temp.insert(arr[i]); // Insert smaller element
            i++;
        }
        else
        {
            temp.insert(vec[j]); // Insert smaller or equal element
            j++;
        }
    }

    // If any elements left in arr[], insert them
    while (i < n)
    {
        temp.insert(arr[i]);
        i++;
    }

    //  If any elements left in vec[], insert them
    while (j < m)
    {
        temp.insert(vec[j]);
        j++;
    }

    //  Display the result
    cout << "After union of both arrays :: ";
    for (auto &it : temp)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    int n, m;

    // Input size and elements of the first array
    cout << "Enter the length of first array :: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements for the first array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Input size and elements of the second array
    cout << "Enter the length of the second array :: ";
    cin >> m;
    vector<int> vec(m);
    cout << "Enter the elements for the second array :: ";
    for (int i = 0; i < m; i++)
    {
        cin >> vec[i];
    }

    // Call the function to compute and print union
    twoUnion(arr, vec, n, m);
}
