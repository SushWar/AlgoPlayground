#include <bits/stdc++.h>
using namespace std;


int main() {
    /* https://unstop.com/code/challange-asesment/250489?moduleId=408

        
     */ 

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);   

    string s1;
    cin>>s1;

    int n = s1.size();
    string result = "YES";
    for(int i=1;i<n;i++){
      if(s1[i-1] > s1[i]){
        result = "NO";
        break;
      }
    }
    cout<<result<<endl;
    return 0;
}