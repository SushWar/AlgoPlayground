#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int realPart(string temp, bool isNegative){

  int res = stoi(temp);

  return isNegative ? res * -1 : res;
}

int imaginePart(string temp, bool isNegative){
  temp.pop_back();
  int res = stoi(temp);

  return isNegative ? res * -1 : res;

}

string multiplication(pp one, pp two){

  pp res;

  res.first = (one.first * two.first) - (one.second * two.second);
  res.second = (one.first * two.second) + (one.second * two.first);

  string answer = "";

  bool firstPart = res.first < 0;
  bool secondPart = res.second < 0;

  // if(firstPart){ 
  //   res.first * -1;
  //   answer += '-';
  // }
  answer += to_string(res.first);
  answer += '+';
  // if(secondPart){ 
  //   res.second * -1;
  //   answer += '-';
  // }
  answer += to_string(res.second) + 'i';
  return answer;
  

}


string helper(string s1, string s2){

  pp one,two;

  string temp = "";
  bool isNegative = false;
  for(int i=0;i<s1.size();i++){
    if(s1[i] == '+'){
      one.first = realPart(temp, isNegative);
      temp = "";
      isNegative = false;
    }
    else{
      if(s1[i]=='-'){
        isNegative = true;
      }
      else{
        temp += s1[i];
      }
    }
  }
  one.second = imaginePart(temp, isNegative);

  // cout<<one.first<<"  --  "<<one.second;

  temp = "";
  isNegative = false;

  for(int i=0;i<s2.size();i++){
    if(s2[i] == '+'){
      two.first = realPart(temp, isNegative);
      temp = "";
      isNegative = false;
    }
    else{
      if(s2[i]=='-'){
        isNegative = true;
      }
      else{
        temp += s2[i];
      }
    }
  }
  two.second = imaginePart(temp, isNegative);

  
  // cout<<two.first<<"  --  "<<two.second;

  string res = multiplication(one,two);

  return res;
  


  
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT 
    
    (1 + -1i) * (1 + -1i)

    (1*1) + (1*-1i) + (-1i * 1) + (-1i * -1i);
     
     1 + (-1i) + (-1i) + (-1)
     0 + -2i
    
    https://unstop.com/code/challange-asesment/250496?moduleId=427
    
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1,s2;

    cin>>s1>>s2;

    string res = helper(s1,s2);

    cout<<res<<endl;

    return 0;
}