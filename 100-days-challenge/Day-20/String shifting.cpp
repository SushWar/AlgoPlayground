#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250545?moduleId=424
    */   

    ios_base::sync_with_stdio(0);

    int n;
    cin>>n;

    string s1;
    cin>>s1;

    string res= "";
    for(int i=0;i<n;i++){
      int shift;
      cin>>shift;

      int idx = ((s1[i]-'a') + shift) % 26;
      res += ('a'+idx);
    }

    cout<<res;
    return 0;
}