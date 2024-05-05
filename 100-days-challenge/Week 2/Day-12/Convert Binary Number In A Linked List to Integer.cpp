#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
      1 1 0 1
      3 2 1 0
      8+4+0+1

      1 0 1 0 1
      4 3 2 1 0
      16+0+4+0+1
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int result = 0;
    int val;
    cin>>val;
    val--;
    while(val >= 0){
      int temp;
      cin>>temp;
      result += pow(2, val)*temp;
      val--;
    }
    cout<<result<<endl;
    return 0;
}