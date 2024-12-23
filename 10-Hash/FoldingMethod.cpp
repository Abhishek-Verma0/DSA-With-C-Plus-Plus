
#include<bits/stdc++.h>
using namespace std;

int fold(int i,int m){
    int sum=0;
    while(i>0){
        sum+=i%100;
        i/=100;
    }
    return sum%m;
}


int main(){
    int keys[]={1,2,3,4,5};
    int m=10;
    cout<<"Hash value is : ";
    for(int i : keys){
        int hashvalue=fold(i,m);
        cout<<i<<" "<<hashvalue;
    }
    return 0;
}






