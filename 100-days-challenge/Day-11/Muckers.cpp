#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s1;
    cin>>s1;

    unordered_map<int, set<char>>order;

    for(int i=0;i<s1.size();i+=2){
      char color = s1[i];
      int rod = s1[i+1] - '0';

      order[rod].insert(color);
    }

    int result = 0;
    for(auto x: order){
      // cout<<"Rod -> "<<x.first<<"  size --> "<<x.second.size()<<endl;
      if(x.second.size()==3){
        result++;
      }
    }

    cout<<result<<endl;
    
       
    return 0;
}