#include <bits/stdc++.h>
using namespace std;

bool palindrome(string x, bool &otherEle){

  int i=0, n=x.size()-1;

  char temp = x[0];
  while(i<n){
    if(x[i] != x[n]){return false;}

    if(temp != x[i] || temp != x[n]){otherEle = true;}

    i++;
    n--;
  }
  return true;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 

    https://unstop.com/code/challange-asesment/250544?moduleId=423

      aabaa
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1;
    cin>>s1;
    bool otherEle = false;
    int result = 0;
    if(palindrome(s1, otherEle)){
      if(!otherEle){
        result = 0;
      }
      else{
        result = s1.size() - 1;
      }
    }
    else{
      result = s1.size();
    }

    cout<<result<<endl;
    return 0;
}