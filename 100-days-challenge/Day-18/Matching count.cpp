#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    https://unstop.com/code/challange-asesment/250527?moduleId=422
      
    */   


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;
    unordered_map<string,vector<string>>order;

    for(int i=0;i<n;i++){
      string type,color,name;

      cin>>type>>color>>name;
      order["type"].push_back(type);
      order["color"].push_back(color);
      order["name"].push_back(name);
    }

    string ruleKey, ruleValue;
    cin>>ruleKey;
    cin>>ruleValue;
    
    int result = 0;
    for(string x: order[ruleKey]){
      if(x==ruleValue){result++;}
    }

    cout<<result<<endl;

    return 0;
}