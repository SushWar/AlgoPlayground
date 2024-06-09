/*
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(NULL);

        int presum = 0, count = 0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int dif = presum % k;
            if(dif < 0){
                dif+=k;
            }
            count+=mp[dif];
            mp[dif]++;
        }
        return count;
    }
};