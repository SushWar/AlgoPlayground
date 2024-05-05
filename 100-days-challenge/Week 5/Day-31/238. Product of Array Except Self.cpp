#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        /*
          1,2,3,4


          left => 1 1 2 6

          right => 24 12 4 1

          res = > 24 12 8 6
        */
        int n = nums.size();
        vector<int>res(n,1);
        for(int i=n-2;i>=0;i--){
            res[i] = res[i+1] * nums[i+1];
        }
        int start = 1;
        for(int i=1;i<n;i++){
            start*= nums[i-1];
            res[i] *= start;
        }
        return res;
        // vector<int>left(n), right(n);

        // left[0] = 1;
        // right[n-1] = 1;

        // for(int i=1;i<n;i++){
        //     left[i] = left[i-1] * nums[i-1];
        // }

        // for(int i=n-2;i>=0;i--){
        //     right[i] = nums[i+1] * right[i+1];
        // }
        
        // for(int i=0;i<n;i++){
        //     nums[i] = left[i] * right[i];
        // }

        // return nums;
    }
};