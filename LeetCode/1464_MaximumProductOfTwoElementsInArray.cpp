#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int res= (nums[i]-1) *(nums[j]-1);
                pq.push(res);
            }
        }
        return pq.top();
    }
};


