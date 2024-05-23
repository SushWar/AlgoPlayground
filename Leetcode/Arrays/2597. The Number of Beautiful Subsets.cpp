/*
*You are given an array nums of positive integers and a positive integer k.

A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.

Return the number of non-empty beautiful subsets of the array nums.

A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums. Two subsets are different if and only if the chosen indices to delete are different.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // vector<vector<int>>show;
    vector<int>visit;
    int result;
public:
    void backtrack(int ptr, int n, int k, vector<int>&nums){

        //base case
        if(ptr >= n){return ;}

        for(ptr;ptr<n;ptr++){
            visit[nums[ptr]]++;
            // temp.push_back(nums[ptr]);
            if(nums[ptr] > k){
                if(!visit[nums[ptr] - k] && !visit[nums[ptr] + k]){
                    result++;
                    // show.push_back(temp);
                    backtrack(ptr+1,n,k,nums);
                }
            }
            else{
                if(!visit[nums[ptr] + k]){
                    result++;
                    // show.push_back(temp);
                    backtrack(ptr+1,n,k,nums);
                }
            }
            visit[nums[ptr]]--;
            // temp.pop_back();
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        
        /*
            7 1 2 4 0 0 
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        result = 0;
        visit.assign(10001,0);
        // sort(begin(nums),end(nums));
        // show.clear();
        // vector<int>temp;
        int n = nums.size();
        backtrack(0,n,k,nums);

        // for(int i=0;i<show.size();i++){
        //     for(int j=0;j<show[i].size();j++){
        //         cout<<show[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return result;
    }
};