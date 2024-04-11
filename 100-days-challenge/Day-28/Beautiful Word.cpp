#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT https://unstop.com/code/challange-asesment/300207?moduleId=433*/  

    ios_base::sync_with_stdio(0) ;
    cin.tie(0);
    cout.tie(0);

    string vowel = "aeiou", ugly = "WORD IS UGLY", beuty = "WORD IS BEAUTIFUL";
    int n;
    cin>>n;

    while(n--){
      string val;
      cin>>val;
      int count = 0;
      int found = val.find_first_of(vowel);
      // cout<<found<<endl;
      if(found >= 0) count++;
       while (found!=val.npos)
        {
          found=val.find_first_of(vowel,found+1);
          
          
          // cout<<found<<endl;
          if(found == -1) break;
          count++;
        }
        // cout<<"found"<<endl;
      if(count%2 == 0){
        cout<<beuty<<endl;
      }
      else{
        cout<<ugly<<endl;
      }
    }
    return 0;
}