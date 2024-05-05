#include <bits/stdc++.h>
using namespace std;

void solve(){
  int n,m;
  cin >> n;
  vector<int>v(n);

  for(int i=0;i<n;i++) cin >> v[i];
  cin >> m;

  int l=1;
  for(int i=0;i<n;i++){
    while(l<v[i]){
      cout<<"Push Pop ";
      l++;
    }
    cout<<"Push ";
    l++;
  }



  //cout<<endl;
  return;
}



int main() {
    int t=1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}