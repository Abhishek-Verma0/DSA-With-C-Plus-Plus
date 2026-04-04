
#include <iostream>

using namespace std;
int main()
{
    int n;
    cout << "enter the number of element you want in the array :: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements which you want in the array :: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int el;
    cout << "Enter the element which you want to insert at the end of an array :: ";
    cin >> el;
    arr[n] = el;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}