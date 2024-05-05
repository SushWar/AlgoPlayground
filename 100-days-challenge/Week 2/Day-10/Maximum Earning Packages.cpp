#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

void createPackage(int idx, int n, vector<string>&packages, vector<pp>alpha, int curr, int &result){

  if(idx >= n){
    result = max(result,curr);
    return ;
  }

  bool canSelect = true;
  int temp = 0;
  vector<pp> tempAlpha = alpha;
  for(char x: packages[idx]){
    int index = x-'a';
    if(tempAlpha[index].first > 0){
      temp += tempAlpha[index].second;
      tempAlpha[index].first--;
    }
    else{
      canSelect = false;
      break;
    }
  }

  if(canSelect){
    createPackage(idx+1, n, packages,tempAlpha, curr+temp, result );
  }
  createPackage(idx+1, n, packages,alpha, curr, result);

  return;

}

int helper(int &numPackages, vector<string>&packages,vector<pp>alpha){

  //recursive method

  int result = 0;

  createPackage(0,numPackages, packages, alpha, 0, result);

  return result;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT

      car mat tag board boss
      a = 3,1
      b = 6
      c = 9
      d = 5
      g = 3
      m = 9
      o = 2
      r = 3
      t = 7


     */   

    ios_base::sync_with_stdio(0)   ;
    cin.tie(0);
    cout.tie(0);


    int numPackages;
    cin>>numPackages;
    vector<string>packages;

    for(int i=0;i<numPackages;i++){
        string val;
        cin>>val;
        packages.push_back(val);
    }

    int boxes;
    cin>>boxes;
    vector<pp>alpha(26,{0,0});
    for(int i=0;i<boxes;i++){
      char val;
      cin>>val;
      alpha[val-'a'].first++;
    }
   
    for(int i=0;i<26;i++){
      int val;
      cin>>val;
      alpha[i].second = val;
    }

    int result = helper(numPackages, packages,alpha);
    cout<<result<<endl;
    // cout<<0<<endl;

    return 0;
}