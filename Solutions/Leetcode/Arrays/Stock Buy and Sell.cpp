#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        

        pair<int,int> mi = {INT_MAX,-1};
        pair<int,int> ma = {INT_MIN,-1};

        int profit = 0;
        int n = prices.size();

        for(int i=0;i<n;i++){
            if(mi.first > prices[i]){
                mi = {prices[i],i};
            }
            if(ma.second <= mi.second || ma.first < prices[i]){
                ma = {prices[i], i};
            }

            if(mi.first < ma.first && mi.second < ma.second){
                profit = max(profit, (ma.first - mi.first));
            }
        }

        return profit;
    }
};

/*
    https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/