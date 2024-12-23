#include <iostream> 

using namespace std;
int partition(int arr[], int low, int high) { 
int pivot = arr[high]; 
int i = (low - 1); 
 
for (int j = low; j <= high - 1; j++) { 
if (arr[j] <= pivot) { 
i++; 
int temp = arr[i]; 
arr[i] = arr[j]; 
arr[j] = temp; 
} 
} 
int temp = arr[i + 1]; 
arr[i + 1] = arr[high]; 
arr[high] = temp; 
return (i + 1); 
} 
void quicksort(int arr[], int low, int high) { 
if (low < high) { 
int pi = partition(arr, low, high); 
quicksort(arr, low, pi - 1); 
quicksort(arr, pi + 1, high); 
} 
} 
int main() { 
int n; 
cout << "Enter the number of elements: "; 
cin >> n; 
int arr[n]; 
cout << "Enter " << n << " elements: "; 
for (int i = 0; i < n; i++) { 
cin >> arr[i]; 
} 
quicksort(arr, 0, n - 1); 
cout << "Sorted array: "; 
for (int i = 0; i < n; i++) { 
cout << arr[i] << " "; 
} 
 
return 0; 
}