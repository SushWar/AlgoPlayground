//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
#define ll long long
class Solution{
    public:
    
    
    
    long long maximumAmount(int n, int arr[]){
        // Your code here
        /*
        https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
        
        2 3 100 , 9, 4
        
        
                2    3    100   9 4
        
        2       4    4    0    9 0   
        3       9    9    0    0 0 
        100     0    0    0    0 0
        9       0    0    0    9 9
        4       0    0    0    0 4 
        
        
        (i = 4 , j = 0){
            i>j dp[i][j] = 0
            i=4, j = 4
            4 += (0,0)
            4 += (0,0)
        
        }
        
        (i = 3 , j = 0){
            i>j dp[i][j] = 0
            i = 3, j = 3
            
            9 += (0,0)
            9 += (0,0)
            
            i=3, j=4
            9 += (0,0)
            4 += (0,0)
            
            
            
        
        }
        
        */
        vector<vector<ll>>dp(n,vector<ll>(n,0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i > j){
                    dp[i][j] = 0;
                    continue;
                }
                
                ll a = arr[i];
                ll b = arr[j];
                
                
                ll first = i+2 < n ? dp[i+2][j] : 0;
                ll second = (i+1<n) && (j-1>=0) ? dp[i+1][j-1] : 0;
                
                
                ll third = j-2>=0 ? dp[i][j-2] : 0;
                ll forth = (i+1<n) && (j-1>=0) ? dp[i+1][j-1] : 0;
                
                a += min(first,second);
                b += min(third, forth);
                
                dp[i][j] = max(a,b);
                
            }
        }
        
        return dp[0][n-1];
        
      
        
        
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends