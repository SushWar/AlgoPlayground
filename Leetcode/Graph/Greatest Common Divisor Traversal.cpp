#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,vector<int>> prime_index;
    unordered_map<int,vector<int>> index_prime;

    void factors(vector<int>nums){

        int n = nums.size();

        for(int i=0;i<n;i++){
            int val = nums[i];
            for(int j=2;j*j <= nums[i];j++){
                if(val % j==0){
                    prime_index[j].push_back(i);
                    index_prime[i].push_back(j);
                    while(val%j==0){
                        val/=j;
                    }
                }
            }

            if(val > 1){
                prime_index[val].push_back(i);
                index_prime[i].push_back(val);
            }
        }

        return;
    }

    void dfs(int node, vector<int>&visitIdx,unordered_map<int,bool>&visitPrime){

        if(visitIdx[node]){return;}
        visitIdx[node]=1;

        for(auto &prime: index_prime[node]){
            if(visitPrime[prime]==true){continue;}
            visitPrime[prime] = true;

            for(auto &index: prime_index[prime]){
                if(visitIdx[index]==true){continue;}
                dfs(index, visitIdx, visitPrime);
            }
        }

        return;
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        prime_index.clear();
        index_prime.clear();

        factors(nums);

        // for(auto x: prime_index){
        //     cout<<"Prime to Index of "<<x.first<<" :- ";
        //     for(auto y: x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }

        

        // for(auto x: index_prime){
        //      cout<<"Index to Prime of "<<x.first<<" :- ";
        //     for(auto y: x.second){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        vector<int>visitIdx(nums.size(),0);
        unordered_map<int,bool>visitPrime;

        dfs(0,visitIdx,visitPrime);

        for(auto &check : visitIdx){
            // cout<<"VistIDX "<<check<<endl;
            if(!check){return false;}
        }

        return true;


    }
};


/*
    https://leetcode.com/problems/greatest-common-divisor-traversal/?envType=daily-question&envId=2024-02-25
*/