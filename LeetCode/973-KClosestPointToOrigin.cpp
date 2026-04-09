#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(k>points.size()) return {{}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<points.size();i++){
            int ans=((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            pq.push({ans,{points[i][0],points[i][1]}});
        }
    vector<vector<int>> res;
    while(k--){
        res.push_back({pq.top().second.first,pq.top().second.second});
        pq.pop();
    }
    return res;
    }
};