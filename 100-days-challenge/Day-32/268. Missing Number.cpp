#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int PreSumXor = 1, PreSumN = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            PreSumN ^= nums[i];
            PreSumXor ^= (i+1);
        }

        return PreSumXor ^ PreSumN;
        
    }
};