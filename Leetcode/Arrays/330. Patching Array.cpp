/*
Given a sorted integer array nums and an integer n, add/patch elements to the array such that any number in the range [1, n] 
inclusive can be formed by the sum of some elements in the array.

Return the minimum number of patches required.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1;
        int res = 0;
        size_t i = 0;

        while(miss <= n){
            if(i<nums.size() && nums[i] <= miss){
                miss += nums[i];
                i++;
            }
            else{
                miss += miss;
                res++;
            }
        }

        return res;
    }
};