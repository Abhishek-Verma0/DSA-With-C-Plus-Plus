#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for( int i : nums){
            mp[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for( auto x : mp){
            pq.push({x.second,x.first});
        }
        vector<int>res;
        while(k--){
            int dig=pq.top().second;
            res.push_back(dig);
            pq.pop();
        }
    return res;
    }
};