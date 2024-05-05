#include <bits/stdc++.h>
using namespace std;

void option1(string s1){
  
  map<char, string>order;
  string temp = "";
  for(int i=0;i<s1.size();i++){
    if(s1[i] == ' '){
      char last = temp[temp.size()-1];
      temp.pop_back();
      // cout<<"for IDX --> "<<last<<" , temp --> "<<temp<<endl;
      order[last] = temp;
      temp = "";
    }
    else{
      temp += s1[i];
    }
  }

  if(temp.size()>0){
     char last = temp[temp.size()-1];
      temp.pop_back();
      // cout<<"for IDX --> "<<last<<" , temp --> "<<temp<<endl;
      order[last] = temp;
      temp = "";
  }
  string result = "";
  for(auto x: order){
    if(x.second.size()>0) result += x.second + " ";
  }
  result.pop_back();
  cout<<result<<endl;
  
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    string s1 = "";
    int t = 10;
    while(t--){
      string str;
      cin>>str;
      if(str.size()>0){
        s1+=str + " ";
      }
      
    }
    
    s1.pop_back();
    option1(s1);
    return 0;
}