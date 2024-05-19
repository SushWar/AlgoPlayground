/*
* There exists an undirected tree with n nodes numbered 0 to n - 1. You are given a 0-indexed 2D integer array edges of length n - 1, where edges[i] = [ui, vi] 
indicates that there is an edge between nodes ui and vi in the tree. You are also given a positive integer k, and a 0-indexed array of non-negative integers nums of 
length n, where nums[i] represents the value of the node numbered i.

Alice wants the sum of values of tree nodes to be maximum, for which Alice can perform the following operation any number of times (including zero) on the tree:

Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
nums[u] = nums[u] XOR k
nums[v] = nums[v] XOR k
Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        /*  
            k = 6
            24 78  1  97  44
            0  1   2  3   4

            0 -> 2
            1 -> 2
            2 -> 0, 1, 4
            3 -> 4
            4 -> 2,3
            
            0   1   2  3    4
            24  78  1  97   44
            30,  0, 7, 103,  0

            0,0,0, 103, 44

            //244
            //
            
            operation on {0,2}
        */

        // unordered_map<int,int>store;
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        ll result = 0, bakra = INT_MAX;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            ll val = nums[i];
            if((val^k) > val){
                result += (val^k);
                bakra = min(bakra, (val^k)-val);
                count++;
            }
            else{
                result += val;
                bakra = min(bakra, val - (val^k));
            }
           
        }

        return count%2 == 0 ? result : result - bakra;
    }
};