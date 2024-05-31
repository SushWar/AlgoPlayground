/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 
You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.
*/

include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        /*  
                [1,2,1,3,2,5]

                XOR of all is coming = 6

                a^b = c

                a = ~b^c
                
                011
                101

                110
                7,4,7,5,4,3

                
        */

       


        
        int n = nums.size();
        if(n==2) return nums;


        ll prefix = nums[0];

        for(int i=1;i<n;i++){
            prefix ^= nums[i];
        }

        ll a = 0, b = 0;
        ll lastBit = prefix & -prefix;


        for(int x: nums){
            if(x & lastBit){
                a ^= x;
            }
        }
        b = prefix ^ a;

        return {(int)a,(int)b};


    }
};