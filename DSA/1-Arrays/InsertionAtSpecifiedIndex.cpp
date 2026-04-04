

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter the number of elements which you want in the array:: ";
    cin >> n;
    int arr[n];
    int el, location;
    cout << "enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the new element which you want to add to array ::";
    cin >> el;
    cout << "Enter the location where you want to add it :: ";
    cin >> location;
    for (int i = n; i >= location; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[location] = el;
    for (int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}