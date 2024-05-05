#include <bits/stdc++.h>
using namespace std;

string convertToDigitsPattern(string s){

  int count = 1;
  char prev = s[0];
  string res = "";

  for(int i=1;i<s.size();i++){
    if(s[i] == prev){
      count++;
    }
    else{
      res += to_string(count) + '-';
      count = 1;
      prev = s[i];
    }
  }

  res += to_string(count);
  return res;

}

void solve(string pattern, vector<string>&order){

  pattern = convertToDigitsPattern(pattern);
  vector<string>res;
  for(string x: order){
    string temp = convertToDigitsPattern(x);
    if(temp == pattern){
      res.push_back(x);
    }
  }


  cout<<res.size()<<endl;
  for(string x: res){
    cout<<x<<" ";
  }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
      abc deq  mee aqq dkd ccc
      abb

      https://unstop.com/code/challange-asesment/250728?moduleId=430
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<string>order(n);

    for(int i=0;i<n;i++){cin>>order[i];}

    string pattern;
    cin>>pattern;

    solve(pattern, order);
    return 0;
}