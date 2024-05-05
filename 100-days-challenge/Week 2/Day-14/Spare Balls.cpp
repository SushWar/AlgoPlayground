#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
        https://unstop.com/code/challange-asesment/250459?moduleId=418
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int box, balls;
    cin>>box>>balls;

    int maxi = -1;
    vector<int>record;
    for(int i=0;i<box;i++){
      int inside;
      cin>>inside;
      maxi = max(maxi, inside);
      record.push_back(inside);
    }

    vector<int>result(box);
    for(int i=0;i<box;i++){
      if(record[i] + balls >= maxi){
        result[i] = 1;
      }
      else{
        result[i] = 0;
      }
    }

    for(int x: result){
      cout<<x<<" ";
    }

    return 0;
}