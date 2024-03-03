#include <bits/stdc++.h>
using namespace std;


int main() {
    /*
        https://unstop.com/code/challange-asesment/250233?moduleId=413
        
        1 2 3 3 5 6
        1 + 3 + 5 => 
    */   

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

    int result = 0;
    for(int i=0;i<n;i+=2){
      result += arr[i];
    }
    cout<<result<<endl;


    return 0;
}