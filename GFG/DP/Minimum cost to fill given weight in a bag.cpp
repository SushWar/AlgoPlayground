/*
    Given an array cost[] of positive integers of size n and an integer w, where cost[i] represents the cost of an i kg packet of oranges, 
    the task is to find the minimum cost to buy exactly w kg of oranges. The cost array has a 1-based indexing. If buying exactly w kg of oranges is 
    impossible, then return -1.
Note:
1. cost[i] = -1 means that i kg packet of orange is unavailable.
2. It may be assumed that there is an infinite supply of all available packet types.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int method1(int idx, int w, vector<int>&cost, vector<vector<int>>&dp){
        if(idx <= 0){
            return 1e9;
        }
        if(w == 0){
            return 0;
        }
        
        if(dp[idx][w] != 1e9){
            return dp[idx][w];
        }
        
        int notTake = method1(idx-1,w,cost,dp);
        int take = 1e9;
        if(w-idx >= 0){
            int repeat = cost[idx-1] + method1(idx,w-idx,cost,dp);
            int notRepeat = cost[idx-1] + method1(idx-1,w-idx,cost,dp);
            
            take =  min(repeat, notRepeat);
        }
        
        return dp[idx][w] = min(notTake, take);
        
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        
        /*
            1. array and weight given
            2. array kai element batate hai iKG packaet of orranges cost
            3. min cost to buy exat w kg of orrange
            4. agar possible nahi toh -1
            
            
            eg 
                .
                1   2   3   4   5
                20, 10, 4, 50, 100
                
                w = 5
                
                possible answers 
                1. 5 => 100
                2. 4+1 => 50 + 20 => 70
                3. 3+2 => 4+10 => 14
                
                1   2 3 4 5
            20  20  
            10  0   
            4   0
            50  0
            100 0
        */
        
        vector<vector<int>>dp(n+1,vector<int>(w+1,1e9));
        
        int res = method1(n,w,cost,dp);
        
        return res == 1e9 ? -1 : res;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends