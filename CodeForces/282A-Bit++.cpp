#include<bits/stdc++.h>
using namespace std;
 

int main(){

    int T;
    cin >> T;
    int num = 0;
    string st = "";
    for (int i = 0; i < T;i++){
        cin>>st;
        if(st.find('+')!=string::npos){
            num++;
        }
        else{
            num--;
        }

    }
    cout << num;
}