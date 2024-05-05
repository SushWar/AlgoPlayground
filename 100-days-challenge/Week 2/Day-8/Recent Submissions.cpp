#include <bits/stdc++.h>
using namespace std;

int helper(vector<int>arr, int n){
  int result = 0;
  deque<int>order;

  for(int t: arr){

    while(!order.empty() && (t-order.front()) >= 5000){
      order.pop_front();
    }

    order.push_back(t);
    result = max(result, (int)order.size());
  }
  return result;
}
 
int main() {
    /* https://unstop.com/code/challange-asesment/250231?moduleId=412

    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int>time(n);
    for(int i=0;i<n;i++){
      cin>>time[i];
    }

    int result = helper(time,n);
    cout<<result<<endl;
    return 0; 
    
}