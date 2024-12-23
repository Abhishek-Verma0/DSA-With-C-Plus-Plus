/** What is quick sort ?  -
 * Quick sort is a popular sorting algorithm that uses a divide-and-conquer strategy to sort an array or list of elements. It works by selecting a 'pivot' element from the array and partitioning the other elements into two sub-arrays, according to whether they are less than or greater than the pivot.

How Quick Sort Works

The algorithm starts by selecting a pivot element from the array.
The pivot element is used to partition the array into two sub-arrays: one containing elements less than the pivot and the other containing elements greater than the pivot.
The algorithm then recursively sorts the two sub-arrays.
Time Complexity of Quick Sort

The average-case time complexity of Quick Sort is O(n log n).
The worst-case time complexity of Quick Sort is O(n^2), which occurs when the pivot is chosen poorly.
Space Complexity of Quick Sort

The space complexity of Quick Sort is O(log n), which is the maximum depth of the recursion tree.
Advantages of Quick Sort

Quick Sort is a fast and efficient sorting algorithm.
It is relatively simple to implement.
It is a stable sort, meaning that the order of equal elements is preserved.
Disadvantages of Quick Sort

Quick Sort can have poor performance if the pivot is chosen poorly.
It is not a stable sort, meaning that the order of equal elements is not preserved.
 */

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            cnt++;
        }
    }
    // palce pivot at right index
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);
    // left and righe part
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while(arr[j]>=pivot){
            j--;
        }

        if(i <pivotIndex && j> pivotIndex){
            swap(arr[i++],arr[j--]);
        }

    return pivotIndex;
    }


}
 
void quickSort(int arr[], int s, int e)
{
    // basse case;
    if (s >= e)
    {
        return;
    }
    // now do partiton
    int p = partition(arr, s, e);
    // left part sorting
    quickSort(arr, s, p - 1);
    // right part sorting
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[5] = {2, 4, 1, 6, 9};
    int n = 5;

    quickSort(arr, 0, n - 1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}