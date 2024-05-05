#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        /*
            
        */
        int n = nums.size();
        vector<int>prev;
        prev.push_back(nums[0]);

        for(int i=1;i<n;i++){
            if(prev.back() < nums[i]){
                prev.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(begin(prev),end(prev), nums[i]) - prev.begin();
                prev[idx] = nums[i];
            }
        }

        return prev.size();
        
    }
};