//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution
{   
    int MOD = 1e9+7;
    public:
    //Function to find sum of all possible substrings of the given string.
    // https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1
    long long sumSubstrings(string s){
        
        // your code here
        /*
        
            
        509
        
        0 => 50
        9 => (50*10) + (9 * 3) => 500 + 27 => 527 + 50 + 5
        */
        int n = s.size();
        vector<ll>dp(n,0);
        
        
        dp[0] = s[0]-'0';
        ll res = dp[0];
        for(int i=1;i<n;i++){
            
            ll val = s[i]-'0';
            
            dp[i] = ((dp[i-1]*10)%MOD + (val * (i+1))%MOD)%MOD;
            res = (res + dp[i])%MOD;
        }
        
        
       
        return res;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends