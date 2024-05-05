#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        


        if(nums.size()==1) return true;
        

        int curr = nums[0];
        if(curr == 0){return false;}
        for(int i=1;i<nums.size()-1;i++){
            curr--;
            curr = max(curr,nums[i]);
            if(curr == 0){return false;}
        }

        return true;
    }
};