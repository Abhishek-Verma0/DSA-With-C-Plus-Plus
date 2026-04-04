#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "Enter the number of elements which you need in array :: ";
    cin >> n;
    int arr[n];
    cout << "enter the elements of an array ::";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int find;
    cout << "Enter the element which you want to check whether it is present in the array or not :: ";
    cin >> find;
    int low = 0;
    int high = n - 1;
    int boo = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == find)
        {
            cout << "element found at index " << mid;
            boo = 1;
            break;
        }
        if (arr[mid] > find)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (!boo)
    {
        cout << "Element does not exist in the array ";
    }
}