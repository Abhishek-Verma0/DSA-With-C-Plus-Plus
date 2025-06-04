#include<bits/stdc++.h>
using namespace std;

void leftRot(vector<int>&arr,int &left,int &n){
    
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    cout << "Enter how many times you want to rotate the array to left :: ";
    int left;
    cin >> left;

    leftRot(arr, left, n);
}