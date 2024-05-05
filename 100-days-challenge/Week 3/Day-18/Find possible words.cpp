#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    ovjad
      https://unstop.com/code/challange-asesment/250524?moduleId=422
    */   


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;
    
    vector<string>store;
    

    for(int i=0;i<n;i++){
      string temp;
      cin>>temp;
      
      store.push_back(temp);
    }

    string words;
    cin>>words;

    vector<int>alpha(26,0);

    for(char x: words){
      alpha[x-'a']++;
    }

    int result = 0;

    for(int i=0;i<n;i++){
      vector<int>temp = alpha;
      
      string check = store[i];
      bool success = true;
      for(char x: check){
        if(temp[x-'a'] == 0){success = false; break;}
        temp[x-'a']--;
      }

      if(success){
        result += check.size();
      }
    }

    cout<<result<<endl;


    
    


    return 0;
}