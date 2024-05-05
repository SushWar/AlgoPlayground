#include <bits/stdc++.h>
using namespace std;


int main() {
    /* https://unstop.com/code/challange-asesment/250500?moduleId=411 */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string comp;
    int models, result = 0;

    cin>>comp;
    cin>>models;

    vector<string>cars(models);
    vector<int>order(26,0);

    for(int i=0;i<models;i++){
      cin>>cars[i];
    }

    for(char x: comp){
      order[x-'a']++;
    }

    for(string x: cars){
      int tempSize = x.size();
      int i = 0;
      bool selected = true;
      while(i<tempSize){
        if(order[x[i]-'a'] == 0){selected = false; break;}
        i++;
      }

      if(selected){result++;}
      
    }
    
    cout<<result<<endl;
    return 0;
}