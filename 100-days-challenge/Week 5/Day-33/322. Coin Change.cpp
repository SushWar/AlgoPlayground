#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
   

    int coinChange(vector<int>& coins, int amount) {

        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);
        
        if(amount == 0) return 0;

        int n = coins.size();
        // vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        vector<int>prev(amount+1,0), curr(amount+1,0);

        for(int i=0;i<=amount;i++){
            if(i % coins[0] == 0){
                // dp[0][i] = i/coins[0];
                prev[i] = i/coins[0];
            }
            else{
                // dp[0][i] = 1e9;
                prev[i] = 1e9;
            }
        }

        for(int i=1;i<n;i++){
            
            for(int j=0;j<=amount;j++){
                int notPick = prev[j] ;//dp[i-1][j];
                int pick = INT_MAX;
                if(coins[i] <= j){
                    pick = 1 + curr[j-coins[i]];//dp[i][j-coins[i]];
                }

                // dp[i][j] = min(pick, notPick);
                curr[j] = min(pick, notPick);
            }
            prev = curr;
        }

        return prev[amount] >= 1e9 ? -1 : prev[amount];
    }
};