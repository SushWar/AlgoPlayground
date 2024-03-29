#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250445?moduleId=427
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    string s1,s2;

    cin>>n;
    cin>>s1;
    cin>>m;
    cin>>s2;

    int i=0, j=0;
    string res = "";
    while(i<n && j<m){
      res += s1[i];
      res += s2[j];
      i++;
      j++;
    }

    while(i<n){
      res += s1[i];
      i++;
    }
    while(j<m){
      res += s2[j];
      j++;
    }

    // cout<<"size --> "<<res.size()<<endl;
    cout<<res<<endl;

    return 0;
}