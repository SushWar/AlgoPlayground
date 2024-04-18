//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to find two repeated elements.
    vector<int> twoRepeated (int arr[], int n) {
        // Your code here
        
        /*
            {1,2,1,3,4,3}
            len = 6
            
            0 => idx = 1%6 => arr[1] => 2+6 => 8/6 >= 2 ==> yes => insert idx => arr[1] = 8
            1 => idx = 2%6 => arr[2] => 1+6 => 7/6 >= 2 ==> NO => => arr[2] = 7
            2 => idx = 8%6 => arr[2] => 1+6 => 7/6 >= 2 ==> NO =>  => arr[2] = 7
            3 => idx = 3%6 => arr[3] => 3+6 => 9/6 >= 2 ==> NO =>  => arr[3] = 9
            4 => idx = 4%6 => arr[3] => 3+6 => 9/6 >= 2 ==> NO =>  => arr[3] = 9
        */
        
        vector<int>res;
        int len = n+2;
        for(int i=0;i<len;i++){
            int idx = arr[i]%len;
            arr[idx] = arr[idx]+len;
            if(arr[idx]/len >= 2){
                res.push_back(idx);
            }
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t;
    
    while(t--)
    {
        cin>>n;
        
        int a[n+2];
        
        for(int i=0;i<n+2;i++)
            cin>>a[i];
        
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}

// } Driver Code Ends