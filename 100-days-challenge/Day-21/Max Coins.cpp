#include <bits/stdc++.h>
using namespace std;

int helper(int temp){

  int sum = 0;
  while(temp){
    sum += temp%10;
    temp /= 10;
  }

  return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250588?moduleId=425
    */ 
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<int>alpha(54,0);
    int mini = INT_MAX, maxi = INT_MIN;

    for(int i=0;i<n;i++){
      int temp;
      cin>>temp;
      mini = min(mini, temp);
      maxi = max(maxi, temp);
      // int num = helper(temp);
      // cout<<num<<endl;
    }

    for(int i=mini;i<=maxi;i++){
      int num = helper(i);
      alpha[num]++;
    }

    int res = INT_MIN;

    for(int x: alpha){
      res = max(res, x);
    }

    cout<<res;

    return 0;
}