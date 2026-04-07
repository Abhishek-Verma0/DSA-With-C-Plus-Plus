#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i : arr){
            int ans= abs(x-i);
            pq.push({ans,i});
        }
    if(k>arr.size()) return {};
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
         sort(res.begin(),res.end());
         return res;
    }

};