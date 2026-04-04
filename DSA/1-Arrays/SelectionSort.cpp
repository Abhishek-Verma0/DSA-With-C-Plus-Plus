
/*
main question how selection sort works we asssume the very first element of an array as the least element then we further compare it to the
 other elements in an array if we found any less element than we assumed we update to the least if not then continue then we assume the second element as the least element of an array hence it goes on till we not get the sorted one
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "enter the index of an array ::";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements for array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    cout << "Printing the sorted array :: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
