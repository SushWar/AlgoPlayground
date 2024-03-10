#include <bits/stdc++.h>
// #deine pp pair<int,int>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    https://unstop.com/code/challange-asesment/295056?moduleId=417
    */   

    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    // pp ing1 = {-1,-1}, ing2 = {-2,-2};
    int ing1 = -1, ing2 = -2;
    for(int i=0;i<n;i++){
      int sweet;
      cin>>sweet;

      if(ing1 < sweet){
        ing2 = ing1;
        ing1 = sweet;
      }
      else{
        if(ing2 < sweet){
          ing2 = sweet;
        }
      }
    }

    cout<<(ing1*ing2);
    return 0;
}