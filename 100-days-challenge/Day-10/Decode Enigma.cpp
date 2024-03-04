#include <bits/stdc++.h>
using namespace std;

void option1(string enigma){
   unordered_map<string, string>order;

    order["S"] = "send";
    order["[]"] = "the";
    order["[sps]"] = "ships";
    string temp = "";
    string result = "";
    for(char x: enigma){
      if(order.count(temp)){
        result += order[temp] + " ";
        temp = x;
      }
      else{
        temp += x;
      }
    }
     if(order.count(temp)){
        result += order[temp] + " ";
        temp = "";
      }
    result.pop_back();
    cout<<result<<endl;
}

void option2(string s){

  string result = "";

  for(int i=0;i<s.size();){
    if(s[i] == 'S'){
      result += "send ";
      i++;
    }
    else if(s[i+1] == ']'){
      result += "the ";
      i+=2;
    }
    else{
      result += "ships ";
      i+=5;
    }
  }

  cout<<result<<endl;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

  

    string enigma;
    cin>>enigma;
    // cout<<enigma.size();
    // option1(enigma);

    option2(enigma);
    return 0;
}