#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250561?moduleId=423
    */   

    ios_base::sync_with_stdio(0);

    string write;
    getline(cin,write);

    string keys;
    cin>>keys;

    // cout<<write<<" --> "<<keys;

    vector<int>broke(26,0);

    for(auto x: keys){
      broke[x-'a']++;
    }

    int n = write.size();
    
    bool possible = true;
    int result = 0;
    for(int i=0;i<n;i++){
      
      

      char ch = write[i];
      if(ch == ' '){

        if(possible){result++;}
        possible = true;
      }
      else{
        if(broke[ch-'a'] > 0){
          possible = false;
        }
        
      }
      
    }

    if(possible){result++;}
    cout<<result<<endl;

    return 0;
}