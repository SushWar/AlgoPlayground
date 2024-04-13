#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(begin(nums),end(nums));

        vector<vector<int>>res;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k=n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    res.push_back({nums[i],nums[j],nums[k]});

                    while(j<k && nums[j] == nums[j+1]) j++;
                    while(j<k && nums[k] == nums[k-1]) k--;

                    j++;
                    k--;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }

        return res;
    }
};