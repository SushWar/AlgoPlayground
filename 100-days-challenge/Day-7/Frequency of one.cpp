#include <bits/stdc++.h>
using namespace std;


void builtInMethod(int n){
  int result = 0;
    for(int i=1;i<=n;i++){
      result += __builtin_popcount(i);
    }

    cout<<result<<endl;
    return;
}

void selfMethod(int n){

  int result = 0;

  for(int i=1;i<=n;i++){
    int temp = i;

    while(temp > 0){
      result += (temp&1);
      temp = temp>>1;
    }
  }

  cout<<result<<endl;
}

int main() {
    /* https://unstop.com/code/challange-asesment/250869?moduleId=411 */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    // builtInMethod(n);
    selfMethod(n);
    return 0;
}