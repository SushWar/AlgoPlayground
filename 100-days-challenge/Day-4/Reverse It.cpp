#include <bits/stdc++.h>
using namespace std;


int main() {
    /* https://unstop.com/code/challange-asesment/250903?moduleId=408
     */ 

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1;
    char ch;

    cin>>s1>>ch;
    int n = s1.size();
    for(int i=n-1;i>=0;i--){
      if(s1[i]==ch){
        reverse(s1.begin()+i, s1.end());
        break;
      }
    }
    cout<<s1;
    return 0;
}