#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int T;
    cin>>T;
    while(T--){

       
            int sz;
            
            string st;
            
            cin>>sz>>st;
            
            if(sz==1){
                cout<<st<<endl;
                continue;
            }
            
            string res="";
            int i=0;
            int j=sz-1;
            int turn=0;
            while(i<=j){
                if(turn%2==0){
                    turn++;
                     string a=st[i]+res;
                string b=res+st[i];
                if(a<b){
                    res=a;
                    i++;
                }
                else{
                    res=b;
                    i++;
                }
                }
                else{
                    turn++;
                string c=st[j] +res;
                string d=res+st[j];
                if(c>d){
                    res=c;
                    j--;
                }
                else{
                    res=d;
                    j--;
                }
                }
               

            }
            
            cout<<res<<endl;
        
    }
    return 0;
}
