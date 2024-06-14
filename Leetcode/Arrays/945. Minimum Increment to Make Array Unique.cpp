/*
You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

     /*
        1 1 2 2 2 3 3 3 3
         
     */ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sort(begin(nums),end(nums));

    int count = 0;
    for(int i=1;i<nums.size();i++){
        if(nums[i] <= nums[i-1]){
            count += nums[i-1] - nums[i] + 1;
            nums[i] = nums[i-1]+1;
        }
    }

    return count;


    // vector<int>order(1000000, 0);
    // int count = 0;
     

    //  for(int i=0;i<nums.size();i++){
    //     if(!order[nums[i]]){
    //         order[nums[i]] = 1;
    //     }
    //     else{
    //         int temp = nums[i];
    //         while(order[temp]){
    //             temp++;
    //             count++;
    //         }
    //         order[temp] = 1;
    //     }
    //  }

    //  return count;



    }
};