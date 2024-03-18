#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool palindrom(string val){

  int i=0,n=val.size()-1;

  while(i<n){
    if(val[i] != val[n]){
      return false;
    }
    i++;
    n--;
  }

  return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
      string val;
      cin>>val;
      if(palindrom(val)){
        cout<<val<<endl;
        return 0;
      }
    }

    // cout<<
    return 0;
}