#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

    /*https://unstop.com/code/challange-asesment/250749?moduleId=407*/
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin>>test;

    while(test--){
      string s1;
      cin>>s1;

      if(s1[s1.size()-1]=='0'){
        cout<<0<<endl;
      }
      else{
        cout<<1<<endl;
      }
    }
    return 0;
}