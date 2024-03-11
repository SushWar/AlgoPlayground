#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
        https://unstop.com/code/challange-asesment/250452?moduleId=418
    */ 

    ios_base::sync_with_stdio(0)  ;
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    vector<string>strips(n);

    for(int i=0;i<n;i++){
      cin>>strips[i];
    }

    int result = 0;
    for(int col=0;col<m;col++){
      for(int row=1;row<n;row++){
        if(strips[row-1][col] > strips[row][col]){
          result++;
          break;
        }
      }
    }

    cout<<result<<endl;
    return 0;
}