#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
      1 + 2 + 3 + 4

      https://unstop.com/code/challange-asesment/250530?moduleId=422
    */   


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin>>n;

    ll sum = 0;
    ll counter = 1;

    while(sum < n){
      ll temp = sum + counter;
      if(temp + counter + 1 > n){break;}
      else if(temp + counter + 1 == n){counter++; break;}
      sum = temp;
      counter++;
    }

    cout<<counter<<endl;


    return 0;
}