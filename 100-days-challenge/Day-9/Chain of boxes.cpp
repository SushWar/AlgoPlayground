#include <bits/stdc++.h>

using namespace std;


int main() {
    /* https://unstop.com/code/challange-asesment/250236?moduleId=413 */  

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    reverse(begin(arr),end(arr));
    for(int i=0;i<n;i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}