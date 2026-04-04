

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of element to be in the arrray :: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Printing the sorted array :: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}