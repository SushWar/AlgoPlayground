#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250563?moduleId=424
    */   

    int n;
    cin>>n;
    vector<int>height(n);
    for(int i=0;i<n;i++){
      cin>>height[i];
    }

    vector<int>temp = height;

    sort(begin(temp),end(temp));

    int count = 0;

    for(int i=0;i<n;i++){
      if(temp[i] != height[i]){
        count++;
      }
    }

    cout<<count<<endl;


    return 0;
}