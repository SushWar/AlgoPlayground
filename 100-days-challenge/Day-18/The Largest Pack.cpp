#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/250913?moduleId=422*/   

    

    ll n;
    cin>>n;

    ll result = 1;

    while(result < n){
       ll temp = result<<1;
       if(temp > n) break;
       else if(temp == n){result = temp; break;}
       result = temp;
    }

    cout<<result<<endl;

    return 0;
}