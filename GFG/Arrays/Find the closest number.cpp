//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        
        
        int low = 0, high = n-1;
        int diff = INT_MAX, result = 0;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            int tempDiff = abs(arr[mid] - k);
            if(tempDiff < diff){
                diff = tempDiff;
                result = arr[mid];
            }
            else if(tempDiff == diff){
                result = max(result,arr[mid]);
            }
            
            if(arr[mid]< k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            
        }
        
        return result;
        
        
        
        
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends