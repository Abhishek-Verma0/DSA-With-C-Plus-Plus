#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int cnt=1;
        if(n==1) return n;
        priority_queue<long,vector<long>,greater<long>>pq;
        set<long>st;
        pq.push(1);
        long num=1;
        while(cnt<=n){

           num=pq.top();
           pq.pop();
           if(st.insert(num*2).second) pq.push(num*2);
           if(st.insert(num*3).second) pq.push(num*3);
           if(st.insert(num*5).second) pq.push(num*5);
            cnt++;
        }
 return (int)num;
    }
};