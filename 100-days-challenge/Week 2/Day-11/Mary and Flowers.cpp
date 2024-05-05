#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

// vector<int> helper(vector<int>&arr, int &n, int &t){
//   unordered_map<int>order

//   for(int i=0;i<n;i++){
//     int search = t - arr[i];

//   }
// }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t, lptr, rptr;

    cin>>n>>t;

    vector<int> ip(n);

    for(int i=0; i<n; i++) cin>>ip[i];

    lptr=0;
    rptr=n-1;

    for(int i=0; i<n; i++){
        if(ip[lptr] + ip[rptr] == t)
            break;
        else if(ip[lptr] + ip[rptr] > t)
            rptr--;
        else
            lptr++;
    }

    cout<<lptr<<" "<<rptr;

    return 0;
    
}