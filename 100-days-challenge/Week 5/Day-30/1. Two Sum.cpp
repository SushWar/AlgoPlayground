#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
       unordered_map<int,int>order;
        int n = nums.size();
       for(int i=0;i<n;i++){
        int find = target - nums[i];
    
        if(order.count(find)){
            return {order[find], i};
        }

        order[nums[i]] = i;
       }

    return {0};





    }
};