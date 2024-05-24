/*
Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. 
Let the sum of the elements of these two subsets be S1 and S2. 
Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference 
between S1 and S2 is equal to d. Since the answer may be large return it modulo 109 + 7.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

const int mod =(int)1e9+7;
class Solution {
  public:
    
    int countPartition(int idx, int target, vector<vector<int>>&dp, vector<int>&arr){
        
        
        if(idx==0){
            
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
            
        }
        
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        
        
        int notTake = countPartition(idx-1, target, dp, arr);
        int take = 0;
        if(arr[idx] <= target){
            take = countPartition(idx-1, target - arr[idx], dp, arr);
        }
        
        return dp[idx][target] = (take + notTake)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        /*
            abey BC sirf subset count kar jiska difference d hona chaiye 
            1 1 1 1
            
            {1,1} {1,1} {1,1} {1,1} {1,1} {1,1}
            
            5, 2, 6, 4 => 17
            s1 - s2 = d
            s1 = totsum - s2
             
             
             s2 = (17 - 3)/2 => 7
             
             
        */
        
        int total = 0;
        for(int x: arr){
            total += x;
        }
        
        
        //Edge Case
        if(total - d < 0) return 0;
        if((total-d)%2 == 1) return 0;
        
        int s2 = (total - d)/2;
        
        vector<vector<int>>dp(n, vector<int>(s2+1, -1));
        
        
        return countPartition(n-1, s2, dp, arr);
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends