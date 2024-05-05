#include <bits/stdc++.h>
#include <iostream>  
using namespace std;

int stringToNumber(string sh){

  bool negative = false;
  int num = 0;
  for(int i=0;i<sh.size();i++){
    if(sh[i] == '-'){
      negative = true;
    }
    else{
      num += (sh[i]-'0');
      if(i < sh.size()-1) num *= 10;
    }
  }

  return negative ? num * -1 : num;
}

int main() {
    /* https://unstop.com/code/challange-asesment/250404?moduleId=409 */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin>>n;
    stack<int>scoreBoard;

    for(int i=0;i<n;i++){
      string ops;
      cin>>ops;
      
      if(ops == "+"){
        int first = scoreBoard.top();
        scoreBoard.pop();
        int second = scoreBoard.top();
        int sum = first + second;
        scoreBoard.push(first);
        scoreBoard.push(sum);
      }
      else if(ops == "D"){
        int first = scoreBoard.top();
        scoreBoard.push(first*2);
      }
      else if(ops == "C"){
        scoreBoard.pop();
      }
      else{
        
          int val = stringToNumber(ops);
          scoreBoard.push(val);
        
        
        
      }
      
    }

    
    int result = 0;
    while(!scoreBoard.empty()){
      result += scoreBoard.top();
      
      scoreBoard.pop();
    }

    cout<<result<<endl;

    return 0;
}