/*
*   Given an integer array a[] of size n, find the highest element of the array. The array will either be strictly increasing or strictly increasing and then strictly decreasing.

Note: a[i] != a[i+1] 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        
        int low = 0, high = a.size()-1;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(mid == a.size()-1 || (a[mid] > a[mid+1] && a[mid-1] < a[mid])){
                return a[mid];
            }
            else if(a[mid] > a[mid+1]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return 0;
        
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends