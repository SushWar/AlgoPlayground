#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = nums.size();
        int res = nums[0], curr = nums[0], curr2 = nums[0];

        for(int i=1;i<n;i++){
            int ele = max({nums[i], curr*nums[i], curr2*nums[i]});
            curr2 = min({nums[i], curr*nums[i], curr2*nums[i]});
            curr = ele;
            res = max(res, curr);
        }

        return res;

    }
};