#include<bits/stdc++.h>
using namespace std;

void moore(vector<int>&arr,int n){
    
}

int main(){
    int n;
    cout << "Enter the size of an array :: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements for the array :: ";
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    //  finiding the majority element in the array 
 //  majority element in array is element that occured for more than n/2 times 
        //  using efficient way to do so using " MOORES'S VOTING ALGO"
    moore(arr, n);
}