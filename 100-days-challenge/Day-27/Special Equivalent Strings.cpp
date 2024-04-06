#include <bits/stdc++.h>
#define pp pair<int, string>
using namespace std;

string convertEveOdd(string s){

  string res = "";

  vector<pp>alpha;

 for(int i=0;i<s.size();i++){
  int idx = s[i]-'a';
  string put = i%2 == 0 ? "even":"odd";
  alpha.push_back({idx,s[i]+put});
 }

 sort(begin(alpha),end(alpha));
 for(auto x: alpha){
   res += x.second;
 }

 return res;
}

void solve(vector<string>order){

  unordered_map<string,int>alpha;

  for(int i=0;i<order.size();i++){

    string temp = convertEveOdd(order[i]);
    alpha[temp]++;
    // cout<<temp<<endl;
  }

  cout<<alpha.size();
 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 

        abcd cdab cbad xyzz zzxy zzyx 
      https://unstop.com/code/challange-asesment/250474?moduleId=431
       
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    vector<string>order(n);

    for(int i=0;i<n;i++){
      cin>>order[i];
    }

    solve(order);


    return 0;
}