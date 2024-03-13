#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250492?moduleId=420
    */

    ios_base::sync_with_stdio(0)   ;
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    string s1 = "";
    for(int i=0;i<n;i++){
      string temp;
      cin>>temp;
      s1+=temp;
    }

    int m;
    cin>>m;
    string s2 = "";
    for(int i=0;i<m;i++){
      string temp;
      cin>>temp;
      s2+=temp;
    }
    // cout<<"s1 --> "<<s1<<endl;
    // cout<<"s2 --> "<<s2<<endl;
    cout<<(s1==s2 ? "true" : "false")<<endl;
    return 0;
}