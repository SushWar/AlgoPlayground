#include <bits/stdc++.h>
using namespace std;


int main() {
    /*
     https://unstop.com/code/challange-asesment/250490?moduleId=408
        --> {1,0} -> {0,0}
      if (count == 0) {
            candidate = val;
            count = 1;
        } else if (candidate == val) {
            count++;
        } else {
            count--;
        }
        
     */ 

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    unordered_map<int,int>order;

    for(int i=0;i<n;i++){
      int val;
      cin>>val;

      order[val]++;
      if(order[val] == n/2){
        cout<<val<<endl;
        break;
      }
    }
    return 0;
}