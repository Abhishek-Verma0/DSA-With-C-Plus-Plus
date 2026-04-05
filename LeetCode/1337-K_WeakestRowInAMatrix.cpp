#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>res;
        for( int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1) cnt++;
            }
            pq.push({cnt,i});
        }
        if(k>pq.size()) return {};
        while(k--){
            auto [cnt,idx]=pq.top();
            pq.pop();
            res.push_back(idx);
        }
        return res;
    }
};