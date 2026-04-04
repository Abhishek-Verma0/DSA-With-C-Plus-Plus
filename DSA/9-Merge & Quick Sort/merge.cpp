
/**What is merge sort ??
 *
 * Merge sort is a sorting algorithm that follows the divide-and-conquer approach. It works by recursively dividing the input array into smaller subarrays, sorting each subarray, and then merging them back together to form a single, sorted array. This algorithm is known for its efficiency, with a time complexity of O(n log n) in all cases.
 */

#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
     k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    //   merge
    int index1 = 0;
    int index2 = 0;
    k = s; // main array index
    while (index1 < len1 && index2 < len2)
    {
        if(first[index1] < second[index2]){
            arr[k++]=first[index1++];
        }
        else{
            arr[k++]=second[index2++];
        }
    }
    while(index1 <len1){
        arr[k++]=first[index1++];
    }
    while(index2 < len2){
        arr[k++]=second[index2++];
    }

    delete [] first;
    delete [] second;
}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    int mid = (s + e) / 2;
    // left part sort karna hei
    mergeSort(arr, s, mid);

    // right part sort krna hei
    mergeSort(arr, mid + 1, e);

    //  merge
    merge(arr, s, e);
}
 
int main()
{

    int arr[5] = {2, 5, 1, 6, 9};
    int n = 5;
    mergeSort(arr, 0, n - 1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }

}