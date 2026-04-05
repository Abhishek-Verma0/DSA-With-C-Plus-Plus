#include<bits/stdc++.h>

using namespace std;




int main(){
    int T;
    cin >> T;
    vector<string> vec(T);
    for (int i = 0; i < T;i++){
        cin >> vec[i];
    }

    for (int i = 0; i < T;i++){
        string st = vec[i];
        int len = st.size();
        if(len>10){
            string num=to_string(len-2);
            string res = st[0] + num + st[len - 1];
            cout << res<<endl;
        }
        else{
            cout << st<<endl;
        }
    }
        return 0;
}