#include <bits/stdc++.h>
using namespace std;

string helper(string s1){

  int i = 0, n = s1.size();
  string res= "";
  while(i<n){
    if(i+2 < n){
      if(s1[i+2] == '#'){
        int temp = (s1[i]-'0')*10 + (s1[i+1]-'0');
        // cout<<"Temp --> "<<temp<<endl;
        res += ('a'+(temp-1));
        i += 3;
      }
      else{
        int temp = (s1[i]-'0');
        // cout<<"Temp --> "<<temp<<endl;
        res += ('a'+(temp-1));
        i++;
      }
    }
    else{
       int temp = (s1[i]-'0');
      //  cout<<"Temp --> "<<temp<<endl;
        res += ('a'+(temp-1));
        i++;
    }
  }

  return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
      a b c d e f g h i j k l m n o p q r s t u v w x y z
      https://unstop.com/code/challange-asesment/250647?moduleId=426
      123
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1;
    cin>>s1;
    string result = helper(s1); 

    cout<<result<<endl;

    return 0;


}
