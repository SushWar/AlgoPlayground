#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250427?moduleId=427
    */ 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string paren;
    cin>>paren;

    int depth = 0;
    int res = 0;

    for(int i=0;i<n;i++){
      if(paren[i] == '('){
        depth++;
      }
      else if(paren[i] == ')'){
        depth--;
      }
      res = max(res,depth);
    }

    cout<<res<<endl;
    return 0;
}