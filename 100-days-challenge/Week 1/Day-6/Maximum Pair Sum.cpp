#include <bits/stdc++.h>
using namespace std;


int main() {
    /* https://unstop.com/code/challange-asesment/261957?moduleId=410 */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }

    sort(begin(arr),end(arr));
    // cout<<arr[n-1]<<"  ---  "<<arr[n-2];
    int result1 = (arr[n-1] * arr[n-2]) + (arr[n-1] - arr[n-2]);
    int result2 = (arr[0] * arr[1]) + (arr[0] - arr[1]);
    int sum = max(result1, result2);
    cout<<sum;


    return 0;
}