

#include<iostream>
using namespace std;
int main(){
    int n;
    cout << "Enter the length of an array :: ";
    cin >> n;
    int arr[n];
    cout << "Enter the element for an array :: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
int find;
cout<<"enter the element to find :: ";
cin>>find;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == find)
        {
            cout << find << " using linear at index " << i;
        }
    }
}