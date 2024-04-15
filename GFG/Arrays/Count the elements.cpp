//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
        // Your code goes here;
        /*
            sort B -> NlogN
            
            then loop on q and a[i] will get. -> N
            then run a binary search on B to either get a match or if value is greater then stop and return index+1 -> logN
            4
            1 1 4 4 5
            
            
            
            TC -->qlogN
            
            2 3 3 4 4 7 9 10 10 
        */
        // ios_base::sync_with_stdio(0);
        // cin.tie(0);
        // cout.tie(0);
        
        
        vector<int>res;
        sort(begin(b),end(b));
        unordered_map<int,int>visit;
        
        for(int i=0;i<q;i++){
            int idx = query[i];
            if(visit.count(a[idx])){
                res.push_back(visit[a[idx]]);
                continue;
            }
            
            int low = 0, high = n-1;
            while(low <= high){
                int mid = (low+high)/2;
                
                if(b[mid] == a[idx]){
                    while(mid < n && b[mid] == a[idx]){mid++;}
                    res.push_back(mid);
                    break;
                }
                else if(b[mid] > a[idx]){
                    if(mid == 0){
                        res.push_back(0);
                        break;
                    }
                    else{
                        if(b[mid-1] <= a[idx]){
                            res.push_back(mid);
                            break;
                        }
                    }
                   
                    high = mid-1;
                }
                else{
                    if(mid+1 == n){
                        res.push_back(mid+1);
                        break;
                    }
                    else{
                        if(b[mid+1] == a[idx]){
                            mid++;
                            while(mid < n && b[mid] == a[idx]){mid++;}
                            res.push_back(mid);
                            break;
                        }
                        else if(b[mid+1] > a[idx]){
                            res.push_back(mid+1);
                            break;
                        }
                    }
                    low = mid + 1;
                }
            }
            
            visit[a[idx]] = res.back();
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends