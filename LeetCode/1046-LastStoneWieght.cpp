#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i: stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int n1=pq.top();
            pq.pop();
            int n2=pq.top();
            pq.pop();
            n1=n1-n2;
            pq.push(n1);
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};