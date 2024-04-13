#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        /*  0 1 2 3 4 5 6
            4 5 6 7 0 1 2

            target = 0
            
            i=0,j=6 => (6+0)/2 => nums[3] >= nums[i] => i = 3+1
            i=4,j=6 => (6+4)/2 => nums[5] >= nums[i] => i = 5+1
            

        */
        int i = 0, j = nums.size()-1;

        while(i<=j){
            int idx = (i+j)/2;
            if(nums[idx] == target){return idx;}
            else if(nums[idx] >= nums[i]){
                if(target >= nums[i] && target < nums[idx]){
                    j = idx -1;
                }
                else{
                    i = idx +1 ;
                }
            }
            else if(nums[idx] <= nums[j]){
                if(target > nums[idx] && target <= nums[j]){
                    i = idx + 1;
                }
                else{
                    j = idx - 1;
                }
            }
        }

        return -1;
    }
};