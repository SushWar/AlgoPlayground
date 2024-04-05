#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

struct Xgreater
{
    bool operator()( const pp &one, const pp &two ) const {
        
        if(one.first == two.first){
        return one.second < two.second;  
        }
        return one.first < two.first;
    }
};

void solve(string s){

vector<pp>alpha(26,{0,-1});

    for(int i=0;i<s.size();i++){
      int idx = s[i]-'a';
      alpha[idx].first++;
      alpha[idx].second = i;
    }

    sort(alpha.begin(),alpha.end(), Xgreater());

    int res = -1;
    for(int i=0;i<26;i++){
      if(alpha[i].first == 1){
        res = alpha[i].second;
        break;
      }
    }

    cout<<res;
}

void otherWay(string s){

  unordered_map<char,pp>order;

  for(int i=0;i<s.size();i++){
    if(order.count(s[i])){
      order[s[i]].first++;
      order[s[i]].second = i;
    }
    else{
      order[s[i]] = {1,i};
    }
  }

  int mini = INT_MAX;

  for(auto x: order){
    if(x.second.first==1){
      mini = min(mini, x.second.second);
    }
  }

  if(mini == INT_MAX){
    cout<<-1;
    return;
  }
  cout<<mini;
  return ;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/296013?moduleId=430
    */  

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    otherWay(s);

    return 0;
}