#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT https://unstop.com/code/challange-asesment/250873?moduleId=429*/   

    int n;
    cin>>n;

    vector<int>order(n);

    for(int i=0;i<n;i++){
      cin>>order[i];
    }

    sort(begin(order),end(order));

    int diff = order[1] - order[0];
    string result = "true";
    for(int i=2;i<n;i++){
      if(order[i] - order[i-1] != diff){result = "false"; break;}
    }

    cout<<result<<endl;
    return 0;
}