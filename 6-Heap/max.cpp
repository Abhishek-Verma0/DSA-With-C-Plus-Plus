
/// using  zero based indexing to make max heap


#include <bits/stdc++.h>
using namespace std;

void maxheapify(int a[], int i, int hsize) {
    int left = 2 * i + 1;  // Changed to 2*i + 1 for 0-based indexing
    int right = 2 * i + 2; // Changed to 2*i + 2 for 0-based indexing
    int largest = i;

    // Changed conditions to use 0-based indexing
    if (left < hsize && a[left] > a[largest]) {
        largest = left;
    }
    if (right < hsize && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        maxheapify(a, largest, hsize);
    }
}

void buildmaxheap(int a[], int n) {
    // Changed starting point for 0-based indexing
    for (int i = (n/2 - 1); i >= 0; i--) {
        maxheapify(a, i, n);
    }
}

void heapsort(int a[], int n) {
    buildmaxheap(a, n);
    // Modified loop for 0-based indexing
    for (int i = n-1; i > 0; i--) {
        swap(a[0], a[i]);  // Swap with first element (root)
        maxheapify(a, 0, i);  // Heapify reduced heap
    }
}

void print(int *a, int n) {
    // Changed to 0-based indexing
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[] = {5, 2, 5, 7, 6, 89, 66, 33, 47, 85, 65};
    int n = sizeof(a) / sizeof(a[0]);  // Fixed size calculation

    cout << "Original array: ";
    print(a, n);

    heapsort(a, n);

    cout << "After sorting: ";
    print(a, n);

    return 0;
}






/*******************************Using 1 based indexing to make max heap
 */

#include <bits/stdc++.h>
using namespace std;

void maxheapify(int a[], int i, int hsize)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= hsize && a[left] > a[largest])
    {
        largest = left;
    }
    if (right <= hsize && a[right] > a[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(a[i], a[largest]);
        maxheapify(a, largest, hsize);
    }
}

void buildmaxheap(int a[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        maxheapify(a, i, n);
    }
}

void heapsort(int a[], int n)
{
    buildmaxheap(a, n);
    for (int i = n; i > 1; i--)
    {
        swap(a[1], a[i]);
        maxheapify(a, 1, i - 1);
    }
}

void print(int *a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    // 1-based indexing array
    int a[] = {0, 5, 2, 5, 7, 6, 89, 66, 33, 47, 85, 65}; // extra 0 at index 0
    int n = sizeof(a) / sizeof(a[0]) - 1;
     // now correct for 1-based index

        cout<< "Original array: ";
    print(a, n);

    heapsort(a, n);

    cout << "After sorting: ";
    print(a, n);

    return 0;
}
