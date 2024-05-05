#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>>dp;
public:

    int reccurApproach(int k, vector<int>& prices){
        int idx = 0, n = prices.size();
        dp.assign(n+1,vector<int>(2*k,-1));
        return reccur(idx, n, prices, 0, k);
    }

    int reccur(int index, int n, vector<int>& prices, int l, int k){

        //base
        if(index >= n || 2*k==l){
            return 0;
        }

        //memorization
        if(dp[index][l] != -1){
            return dp[index][l];
        }

        //choice
        int profit = 0;

        if(l%2==0){
            
            int buy = (-prices[index] + reccur(index+1, n, prices, l+1, k));
            int skip = 0 + reccur(index+1,n,prices, l, k);
            profit = max(buy, skip);
        }
        else{
            int sell = (prices[index] + reccur(index+1,n,prices,l+1,k));
            int skip = 0 + reccur(index+1,n,prices, l, k);
            profit = max(sell, skip);
        }

        return dp[index][l] = profit;

    }
    int optimalApproach(int k, vector<int>& prices){
        vector<int>cost(k+1,INT_MAX),profit(k+1,0);
        for(int i=0;i<prices.size();i++){
            for(int j=1;j<=k;j++){
                cost[j] = min(cost[j],prices[i]-profit[j-1]);
                profit[j] = max(profit[j],prices[i]-cost[j]);
            }
        }
        return profit[k];
    }
    int maxProfit(int k, vector<int>& prices) {
        
        // return reccurApproach(k,prices);
        return optimalApproach(k,prices);
        
    }
};