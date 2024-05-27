/*
You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums 
that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.

 
*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=1,r=100;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int x=0;
            for(int i=0;i<nums.size();++i)
                x+=(nums[i]>=mid);
            // cout<<mid<<" "<<x<<endl;
            if(x==mid)
                return x;
            if(x>mid)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
};