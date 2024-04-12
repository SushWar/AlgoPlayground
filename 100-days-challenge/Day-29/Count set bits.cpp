#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT https://unstop.com/code/challange-asesment/250206?moduleId=434*/   

    int n;
    cin>>n;
    int res = 0;

    for(int i=1;i<=n;i++){
      res += __builtin_popcount(i);
    }
    cout<<res;
    return 0;
}