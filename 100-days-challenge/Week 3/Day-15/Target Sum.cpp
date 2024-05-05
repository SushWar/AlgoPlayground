#include <bits/stdc++.h>
using namespace std;

void reccur(int idx, vector<int>arr, int n ,int k, int &count, int sum){
  if(idx == n){
    if(sum == k){count++;}
    return;
  }

  reccur(idx+1,arr,n,k,count, (sum + arr[idx]));
  reccur(idx+1,arr,n,k,count, (sum + (arr[idx] * -1)));
  return;
}
int helper(vector<int>arr, int n, int k){

  int count = 0;
  
  reccur(0,arr,n,k,count, 0);
  return count;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250466?moduleId=419
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int>arr;
    
    for(int i=0;i<n;i++){
      int val;
      cin>>val;
      
      arr.push_back(val);
    }
    int target;
    cin>>target;
    int result = helper(arr, n, target);
    
    cout<<result<<endl;
    
    return 0;
}