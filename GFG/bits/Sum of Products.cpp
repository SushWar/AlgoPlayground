//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
#define ll long long
class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        
        /*
        
            5 10 15 20
            0
        */
       
       ll res = 0; 
       
    
        for(int i=0;i<32;i++){
            ll count = 0;
            for(int j=0;j<n;j++){
                if((arr[j] >>i)&1 == 1){
                    count++;
                }
            }
            
            ll pairs = (count*(count-1))/2;
            res += (1<<i)*pairs;
        }
       
       return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends