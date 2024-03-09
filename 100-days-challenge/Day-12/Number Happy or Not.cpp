#include <bits/stdc++.h>
using namespace std;

int option1(int num, unordered_set<int>&visit){

  if(num == 1){
    return 1;
  }
  else if(num == 0){
    return 0;
  }

  int temp = 0;
  while(num > 0){
    int last = num%10;
    num/=10;
    temp += (last*last);
  }
  if(visit.count(temp)){return 0;}
  visit.insert(temp);
  return option1(temp,visit);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
      7
    */

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    cin>>num;
    unordered_set<int>visit;
    int result = option1(num, visit);
    // for(auto x: visit){
    //   cout<<x<<endl;
    // }
    cout<<result<<endl;
    // int temp = 7;
    // cout<<sqrt(temp);
    return 0;
}