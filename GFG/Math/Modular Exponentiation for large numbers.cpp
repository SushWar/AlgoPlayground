/*
*Implement pow(x, n) % M.
In other words, for a given value of x, n, and M, find  (xn) % M.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    
		    /*  
		        
		        2^1 % 10 = 2
		        2^2 % 10 = 4
		        2^3 % 10 = 8
		        2^4 % 10 = 6
		        2^5 % 10 = 2
		        2^6 % 10 = 4
		        2^7 % 10 = 8
		        2^8 % 10 = 6
		        
		        
		        2 - 2
		        4 - 4 
		        8 - 8
		        16 - 6
		        32 - 2
		        64 - 4
		        128 - 8
		        256 - 6
		        512 - 2
		        1024 - 4
		        2048 - 8
		           
		        2 4 8 6
		        
		        
		        
		        3^1 % 4 = 3
		        3^2 % 4 = 1
		        3^3 % 4 = 3
		        3^4 % 4 = 1
		        
		        3,1
		        
		        3 - 3
		        9 - 1
		        27 - 3
		        81 - 1
		        
		             
		    */
		  
		  ll power = n;
		  ll val = 1;
		  ll base = x;
		  
		  while(power > 0){
		      if(power%2 != 0){
		          val *= base;
		          val %= M;
		          power--;
		      }
		      else{
		          base *= base;
		          base %= M;
		          power/=2;
		      }
		  }
		  
		  return val % M;
		    
		    
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends