#include <bits/stdc++.h>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    ios_base::sync_with_stdio(0)   ;
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<pair<int,int>>list(n);

    for(int i=0;i<n;i++){
      int val;
      cin>>val;
      list[i] = {val,0};
    }

    for(int i=0;i<n;i++){
      int val;
      cin>>val;
      list[i].second = val;
    }

    for(auto x: list){
      cout<<x.first<<" "<<x.second<<" ";
    }
    return 0;
}