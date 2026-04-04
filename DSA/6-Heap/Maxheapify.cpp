/***
 * heapify algorithm
 * having a random data and converting into heap
 *
 *
 * leaf node lies btw (n/2)+1  to nth index
 * leaf node can be called as heap in itself
 *
 */


//  here we used heapify algorithtm to make max heap
//  O(nlog(n))  time complexity
#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the array after heapify :: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}