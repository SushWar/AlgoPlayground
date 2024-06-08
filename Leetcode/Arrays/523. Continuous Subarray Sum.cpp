/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        /*
            1,3,6,0,9,6,9   k=7

            1,3 => 4%7 = 4
            4+6 => 10%7 = 3
            10+0 => 10%7 = 3
            10+9 => 19%7 = 5
            19+6 => 25%7 = 4
            25%9 => 34%7 = 6
        */
       int currentSum = nums[0];
        int length = nums.size();
        int index, tempSum;
        
        for (int i = 1; i < length; i++) {
            if (nums[i] == nums[i - 1] && nums[i] == 0) {
                return true;
            }
            
            currentSum += nums[i];
            
            if (currentSum % k == 0) {
                return true;
            }
            
            index = 0;
            tempSum = currentSum;
            
            while ((i - index) > 1 && tempSum >= k) {
                tempSum -= nums[index++];
                
                if (tempSum % k == 0) {
                    return true;
                }
            }
        }
        
        return false;
    }
};