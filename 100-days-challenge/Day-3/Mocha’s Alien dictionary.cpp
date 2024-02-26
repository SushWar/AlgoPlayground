#include <bits/stdc++.h>
using namespace std;


int main() {
    
  /*
    https://unstop.com/code/challange-asesment/250171?moduleId=407

  */

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string check;
    cin>>check;

    int n;
    cin>>n;
    unordered_map<string,int>dir;
    for(int i=0;i<n;i++){
      string s;
      cin>>s;
      dir[s]++;
    }

    int i = 0, size=check.size();
    string temp="";
    while(i<size){
      temp+=check[i];
      if(dir[temp] > 0){
        temp = ""; 
      }
      i++;
    }

    if(temp.size() > 0){
      cout<<"false"<<endl;
    }
    else{
      cout<<"true"<<endl;
    }
    return 0;
}