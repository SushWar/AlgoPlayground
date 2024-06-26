//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int min_operations(vector<int>& nums) {
        // Code here
        /*
            [1, 2, 3, 6, 5, 4]
            [1]
           2
           2
        */
        
        int n = nums.size();
        vector<int>dp(n,1);
        int res = 1;
       for(int i=1;i<n;i++){
        for(int j=0;j<i;j++)   {
            if(nums[i] - nums[j] >= i-j){
                dp[i] = max(dp[i], dp[j]+1);
                res = max(res, dp[i]);
            }
        }
       }
       
       return n-res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends