#include <bits/stdc++.h>
using namespace std;


int main() {
    /* https://unstop.com/code/challange-asesment/250927?moduleId=413 */  

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
      if(s[i]=='W'){
        cout<<i<<endl;
        return 0;
      }
    }

    cout<<-1<<endl;
    return 0;
}