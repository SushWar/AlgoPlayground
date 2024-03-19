#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250541?moduleId=423*/  

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 


    int n;
    cin>>n;
    string s1;
    cin>>s1;

    // vector<int>alpha(26,0);
    unordered_map<char,int>alpha;

    for(int i=0;i<n;i++){
      // alpha[s1[i]-'a']++;
      alpha[s1[i]]++;
    }

    string res = "-1";
    for(int i=0;i<n;i++){
      if(alpha[s1[i]] == 1){
        res = s1[i];
        break;
      }
    }

    cout<<res<<endl;

    
    return 0;
}