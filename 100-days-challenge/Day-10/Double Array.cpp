#include <bits/stdc++.h>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;
    vector<int>res;
    for(int i=0;i<n;i++){
      int val;
      cin>>val;
      res.push_back(val);
    }

    sort(begin(res),end(res));

    // for(int i=0;i<n;i++){
    //   res.push_back(res[i]);
    // }

    for(int i=0;i<2;i++){
      for(int x: res){
        cout<<x<<" ";
      }
    }
    
    return 0;
}