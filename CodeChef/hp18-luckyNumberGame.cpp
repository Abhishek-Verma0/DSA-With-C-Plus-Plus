#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int cases;
	cin>>cases;
	while(cases--){
	    int n,a,b;
	    cin>>n>>a>>b;
	    vector<int>num(n);
	    
	    for(int i=0;i<n;i++){
	        cin>>num[i];
	    }
	    int nA=0,nB=0,lcm=0;
	    for(int i=0;i<n;i++){
	        if(num[i]%a==0)nA++;
	        if(num[i]%b==0)nB++;
	        if(num[i]%a==0 && num[i]%b==0) lcm++;
	    }
	   //  some overlap issue like it is divisible by a  and b but  also being counted in  lcm and nA and nB so removing that duplicate count
	   nA-=lcm;
	   nB-=lcm;
	   // it is for like bob will be obviously first one to pick  from lcm or comman one 
	   if(lcm>0) nA++;
	   if(nA > nB) cout<<"BOB"<<endl;
	   else cout<<"ALICE"<<endl;
	}
	return 0;
	

}
