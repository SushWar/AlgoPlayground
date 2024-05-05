#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>>dp;
public:
    int reccur(string &ring, string &key ,int ptr, int index){
        int n=ring.size(), m=key.size();
        //base
        if(index >= m){return 0;}

        //memorization
        if(dp[index][ptr] != -1){
            return dp[index][ptr];
        }

        //choice
        int step = 1e9;
        for(int i=0;i<n;i++){
            if(ring[i] == key[index]){
                step = min(step, min(abs(i-ptr), n-abs(i-ptr)) + 1 + reccur(ring, key, i, index+1));
            }
        }

        return dp[index][ptr] = step;
    }
    int findRotateSteps(string ring, string key) {

        /*
            {G,0}, {O,1},  {D,2}, {D,3}, {I,3}, {N,2}, {G,1};

              0 G O D D I N G
            G 0 
            D 0

        */

        
        int ptr = 0, index = 0, n=ring.size(), m=key.size();
        dp.assign(m,vector<int>(n, -1));
        return reccur(ring, key, ptr, index);
        
    }
};