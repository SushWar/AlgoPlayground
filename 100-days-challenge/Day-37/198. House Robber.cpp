#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        
        /*
            1 2 4 
        */
        
        int n = nums.size();

       int prev1 = nums[0], prev2 = 0;

       for(int i=1;i<n;i++){
        int take = nums[i];
        if(i>1){
            take+=prev2;
        }
        int notTake = prev1;
        int curr = max(take,notTake);
        prev2 = prev1;
        prev1 = curr;
       }

       return prev1;
    }
};