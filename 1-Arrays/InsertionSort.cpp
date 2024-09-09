

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the length of an array :: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of an arrray :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    /*
    so now the question arises how this code works  here we assume the first element is already sorted  then compare all unsorted one to the sorted one .. we shift the greater element to the right and smaller element to left side
    */
    for (int i = 1; i < n; i++)
    {
        int key = arr[i]; // we imagine one element  as an already  sorted element as key
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    cout << "sorted array:: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}