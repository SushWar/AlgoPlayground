#include <bits/stdc++.h>
using namespace std;

void fill(vector<int>&order){
  for(int i=3;i<46;i++){
    order[i] = order[i-1] + order[i-2];
  }
}

int main() {
    /* https://unstop.com/code/challange-asesment/250246?moduleId=413 
    1+1+1+1+1+1
    1+1+1+1+2
    1+1+1+2+1
    1+1+2+1+1
    1+2+1+1+1
    2+1+1+1+1
    2+2+2
    1+1+2+2
    2+1+1+2
    2+2+1+1

      1 2 3 4 5 6
      1 2 3 5 8 
    */  

    ios_base::sync_with_stdio(0) ;
    cin.tie(0);
    cout.tie(0);

    vector<int>order(46,0);

    order[1]=1;
    order[2] = 2;

    fill(order);

    int n;
    cin>>n;

    cout<<order[n]<<endl;


    return 0;
}