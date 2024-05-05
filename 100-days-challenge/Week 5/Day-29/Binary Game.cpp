#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 

      0 1https://unstop.com/code/challange-asesment/295057?moduleId=434
    */   

    int n;
    cin>>n;

    for(int i=0;i<=n;i++){
      int val = __builtin_popcount(i);
      cout<<val<<" ";
    }
    return 0;
}