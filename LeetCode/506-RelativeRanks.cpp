#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //  using  max heap to solve it 
        int n=score.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});

        }
        vector<string>res(n);
        int rank=1;
        while(!pq.empty()){
            auto [point, idx]=pq.top();
            pq.pop();
            if(rank==1) res[idx]="Gold Medal";
           else if(rank==2) res[idx]="Silver Medal";
           else if(rank==3) res[idx]="Bronze Medal";
            else{
                res[idx]=to_string(rank);
            }
            rank++;
        }
        return res;
    }
};