#include <bits/stdc++.h>
using namespace std;

void option1(int n, int m, map<int,int>&phase1, vector<int>&phase2){
  vector<int>result;
  for(int i=0;i<m;i++){
    int pick = phase2[i];
    while(phase1[pick] > 0){
      result.push_back(pick);
      phase1[pick]--;
    }
  }

  for(auto x: phase1){
    int temp = x.second;
    int val = x.first;
    while(temp>0){
      result.push_back(val);
      temp--;
    }
  }

  for(int x: result){
    cout<<x<<" ";
  }
  return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250457?moduleId=417
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    map<int,int>phase1;
    vector<int>phase2(m);

    for(int i=0;i<n;i++){
      int temp;
      cin>>temp;
      phase1[temp]++;
    }

    for(int i=0;i<m;i++){
      cin>>phase2[i];
    }

    
    option1(n,m,phase1,phase2);
     
    return 0;
}