#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250900?moduleId=427
    */   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1;

    cin>>s1;

    vector<int>alpha(26,0);

    for(int i=0;i<s1.size();i++){
      alpha[s1[i]-'a']++;
    }

    for(int i=0;i<26;i++){
      if(alpha[i]==0){
        cout<<"False"<<endl;
        return 0;
      }
    }
    cout<<"True"<<endl;
    return 0;
}