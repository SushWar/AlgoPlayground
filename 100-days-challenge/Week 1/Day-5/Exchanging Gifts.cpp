#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int main() {
    /* https://unstop.com/code/challange-asesment/250196?moduleId=409 */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int members, gifts;
    cin>>members>>gifts;

    if(members==1){
      cout<<1<<endl;
      return 0;
    }

    vector<int>count(members,0);
    int result = -1;
    for(int i=0;i<gifts;i++){
      int give, recive;
      cin>>give>>recive;
      count[recive-1]++;

      if(count[recive-1] == members-1){
        result = recive;
      }
    }

    cout<<result<<endl;
    

    return 0;
}