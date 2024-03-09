#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    
      1 -> 3
      2 -> 3
      3 -> 1, 2, 4, 5
      4 -> 3
      5 -> 3
    */ 

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int nodes;
    cin>>nodes;

    unordered_map<int,int>order;
    pp high = {-1,-1};
    for(int i=0;i<nodes;i++){
      int u,v;
      cin>>u>>v;

      order[u]++;
      order[v]++;
      // if(high.first < order[u]){
      //   high = {order[u], u};
      // }
      // else if(high.first < order[v]){
      //   high = {order[v], v};
      // }
    }
    for(auto x: order){
      if(high.first < x.second){
        high = {x.second, x.first};
      }
    }
    cout<<high.second;

    return 0;
}