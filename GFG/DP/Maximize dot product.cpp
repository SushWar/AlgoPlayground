//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		// Your code goes here
		
		/*  https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1
        	10 4
        	
                9   3     9     2     3     5     4     1     8     8
            10  90  90    90    90    90    90    90    0     0     0
            4   0   102   126   126   126   126   126   126   0     0
            3   0   0     129   132   135   141   141   141   150   0               
            8   0   0      0    145   156   175   175   175   205   214          
            
            
            
            
            
                2 3  1  7   8
            3   6 9  9  0   0
            6   0 27 27 51  0
            7   0 0  34 100 107
            
            
            
		*/
		
		vector<int>prev(n,0);
		
		for(int i=0;i<=(n-m);i++){
		    int val = b[0]*a[i];
		    prev[i] = i > 0 ? max(prev[i-1], val) : val;
		}
		
// 		for(int x: prev){
// 		    cout<<x<<" -> ";
// 		}
// 		cout<<endl;
		
		for(int i=1, k = m-1;i<m;i++,k--){
		    vector<int>curr(n,0);
		    for(int j = i; j<=(n-k);j++){
		        int val = b[i] * a[j];
		        curr[j] = max(curr[j-1], prev[j-1] + val);
		    }
		    prev = curr;
		  //  for(int x: prev){
		  //      cout<<x<<" -> ";
		  //  }
		  //  cout<<endl;
		}
		
// 		for(int x: prev){
// 		    cout<<x<<" -> ";
// 		}
// 		cout<<endl;

		
		
		return prev[n-1];
		
	
		
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends