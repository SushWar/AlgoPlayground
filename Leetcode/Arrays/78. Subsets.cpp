/*
* Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>>result;
    set<vector<int>>visit;
public:
    
    void backtrack(int ptr, int n, vector<int>&nums, vector<int>temp){

        //base Case
        if(ptr >= n){
            // if(visit.find(temp) == visit.end()){
            //     visit.insert(temp);
            //     result.push_back(temp);

            // }
            return;
        }

        for(;ptr<n;ptr++){
            
            // backtrack(i+1,n,nums,temp);
            temp.push_back(nums[ptr]);
            result.push_back(temp);
            backtrack(ptr+1,n,nums,temp);
            temp.pop_back();
            
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        /*
            1 phir backtrack + 1
            1,2 phir backtrack + 1
            1,2,3 phir backtrack + 1 => base case insert
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


        int n = nums.size();
        result.clear();
        // visit.clear();
        vector<int>temp;
        result.push_back({});
        backtrack(0,n,nums,temp);

        return result;
    }
};