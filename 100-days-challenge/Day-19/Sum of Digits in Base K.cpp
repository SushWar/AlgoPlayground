#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    100
    9

    80

    1https://unstop.com/code/challange-asesment/250547?moduleId=423
    4
    */  

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 

    int n,k;
    cin>>n;
    cin>>k;

    int sum = 0;
    while(n){
      sum += n%k;
      n /= k;
    }
    cout<<sum<<endl;
    return 0;
}