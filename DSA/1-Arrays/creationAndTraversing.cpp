
#include<iostream>

using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements you want in the array:: "<<endl;
    cin>>n;
    int arr[n];  // here first int indicates which types of data will be stored and second  int specifies the size for elements in the array
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    for(int i=0; i<n;i++){
        cout<<arr[i]<<"  ";
    }

}