#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int reccur(int i, int j, int row, int col){
        if(i >= row || j >= col || i < 0 || j < 0) return 0;
        if(i==row-1 && j == col-1) return 1;

        int right = 0 + reccur(i,j+1,row,col);
        int down = 0 + reccur(i+1,j,row,col);

        return right+down;
    }
    int uniquePaths(int m, int n) {
        
        /*

            0   1   2   3   4   5   6
        0   1   1   1   1   1   1   1
        1   1   2   3   4   5   6   7   
        2   1   3   6   10  15  21  28    
        

        */

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        
        // return reccur(0,0,m,n);
        // vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int>prev(n,1), curr(n,0);

        // for(int i=0;i<n;i++){
        //     // dp[0][i] = 1;
        // }

        // for(int i=0;i<m;i++){
        //     dp[i][0] = 1;
        // }

        for(int i=1;i<m;i++){
            curr[0] = 1;
            for(int j=1;j<n;j++){
                curr[j] = curr[j-1] + prev[j];
            }

            prev = curr;
        }

        return prev[n-1];
    }
};