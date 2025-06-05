
/*
Algorithm: Intersection of Two Arrays (Unique Elements Only)

 Intuition:
- Given two arrays, we want to find common elements that appear in both arrays.
- To do this efficiently, we use a `set` for constant-time lookups.
- By converting one array (vec) into a set, we can check whether each element
of the other array (arr) exists in it in O(1) average time.
- To avoid duplicate intersection results, we store results in a set.

 Approach:
1. Convert second array `vec` to a set `vecSet`.
2. Traverse the first array `arr`.
3. For each element in `arr`, check if it exists in `vecSet`.
    4. If yes, insert it into result set `st`.
    5. Finally, print the elements of set `st`.
    
     Time Complexity:
    - Converting vec to set: O(m)
    - Traversing arr and checking in set: O(n)
    - Total: O(n + m)
    
     Space Complexity:
    - Extra space used for sets: O(n + m)
    */
   
   #include <bits/stdc++.h>
   using namespace std;

// Function to find intersection of two arrays
void twoIntersection(vector<int> &arr, vector<int> &vec, int n, int m)
{
    set<int> st;                             // To store unique intersection elements
    set<int> vecSet(vec.begin(), vec.end()); // Convert vec to set for O(1) lookup

    int i = 0;

    // Traverse the first array
    while (i < n)
    {
        // If current element of arr exists in vecSet, insert into result set
        if (vecSet.find(arr[i]) != vecSet.end())
        {
            st.insert(arr[i]);
        }
        i++;
    }

    // Output the intersection result
    cout << "After intersection :: ";
    for (auto &it : st)
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

    // Call the function to compute and print intersection
    twoIntersection(arr, vec, n, m);

    return 0;
}
