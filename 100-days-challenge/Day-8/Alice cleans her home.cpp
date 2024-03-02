#include <bits/stdc++.h>
using namespace std;



int main() {
    /* https://unstop.com/code/challange-asesment/250202?moduleId=412 */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int>arr;
    int countZero = 0;

    for(int i=0;i<n;i++){
      int val;
      cin>>val;
      if(val==0){
        countZero++;
        continue;
      }
      
      arr.push_back(val);
    }

    while(countZero--){
      arr.push_back(0);
    }

    for(int x: arr){cout<<x<<" ";}

    return 0;
}