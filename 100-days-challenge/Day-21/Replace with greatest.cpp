#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250602?moduleId=425
    */   

    int n;
    cin>>n;

    priority_queue<pp>order;
    
    for(int i=0;i<n;i++){
      int val;
      cin>>val;
      order.push({val,i});
    }

    vector<int>arr(n);
    for(int i=0;i<n-1;i++){
      auto big = order.top();
      int idx = big.second, val = big.first;

      if(i < idx){
        arr[i] = val;
      }
      else{
        while(i >= idx){
          order.pop();
          idx = order.top().second;
        }
        val = order.top().first;
        arr[i] = val;
      }
    }

    arr[n-1] = -1;

    for(int x: arr){
      cout<<x<<" ";
    }
    return 0;
}