#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin >> n;
    int ans=0;
    for (int i = 0; i < n;i++){
        
        int cnt = 0;
        for (int j = 0; j < 3;j++){
            int a;
            cin>>a;
            if(a==1){
                cnt++;
            }
        }
        if(cnt>=2)
            ans++;
    }
    cout << ans;
    return 0;
}