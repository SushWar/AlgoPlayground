#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        /*
            either 1 or 2
            n=1
            1
            n=2
            1+1
            2
            n = 3

            1+1+1
            1+2
            2+1

            n = 4

            1+1+1+1
            1+1+2
            1+2+1
            2+1+1
            2+2
            

            1 2 3 5
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        if(n==1 || n==2) return n;

        vector<int>dp;
        dp.push_back(1);
        dp.push_back(2);

        for(int i=2;i<n;i++){
            int val = dp[i-1] + dp[i-2];
            dp.push_back(val);
        }

        return dp.back();
    }
};