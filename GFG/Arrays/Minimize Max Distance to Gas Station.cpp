/*
We have a horizontal number line. On that number line, we have gas stations at positions 
stations[0], stations[1], ..., stations[N-1], where n = size of the stations array. Now, we add k more gas stations so that d, 
the maximum distance between adjacent gas stations, is minimized. We have to find the smallest possible value of d. Find the answer exactly to 2 decimal places.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ld long double

class Solution {
  public:
    int numberOfGasStationsRequired(ld dist, vector<int> &arr) {
        int n = arr.size(); // size of the array
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
            // if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            //     numberInBetween--;
            // }
            cnt += numberInBetween;
        }
        return cnt;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        /*
            
        */
        
        int n = stations.size();
        ld low = 0;
        ld high = 0;
        
        for(int i=1;i<n;i++){
            high = max(high, (ld)(stations[i] - stations[i-1]));
        }
        
        ld diff = 1e-6 ;
        while (high - low > diff) {
            ld mid = (low + high) / (2.0);
            int cnt = numberOfGasStationsRequired(mid, stations);
            if (cnt > k) {
                low = mid;
            }
            else {
                high = mid;
            }
        }
        return high;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends