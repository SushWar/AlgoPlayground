#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        /*
            A,3
            B,3
            

            A->B->
        */

        unordered_map<char,int>mp;
        int count = 0;
        for(auto x: tasks){
            mp[x]++;
            count = max(count,mp[x]);
        }
        int check = (count-1)*(n+1);
        
        
        for(auto x: mp){
            if(x.second==count){
                check++;
            }
        }
        
        return max((int)tasks.size(),check);
    }   
};

//https://leetcode.com/problems/task-scheduler/?envType=daily-question&envId=2024-03-19