#include <bits/stdc++.h>
using namespace std;

int findPrime(int num){
  if(num <=1) return 0;
  vector<bool>isPrime(num+1,false);
  
  for(int i=2;i*i<=num;i++){
    if(isPrime[i]) continue;
    for(int j=i*i;j<=num;j+=i) isPrime[j] = true;
  }

  int count = 0;
  for(int i=2;i<=num;i++) if(!isPrime[i]) count++;

  return count;
  
}

int helper(string parent){

  int bracket = 0, movesNeeded = 0;

  for(int i=0;i<parent.size();i++){
    if(parent[i] == '('){
      bracket++;
    }
    else if(parent[i] == ')' && bracket == 0){movesNeeded++;}
    else if(parent[i] == ')'){
      bracket--;
    }
  }

  return findPrime(bracket + movesNeeded);

  
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT
    
    https://unstop.com/code/challange-asesment/250228?moduleId=428
     */

    ios_base::sync_with_stdio(0)   ;
    cin.tie(0);
    cout.tie(0);

    string parent;
    cin>>parent;

    int getPrime = helper(parent);

    cout<<getPrime<<endl;
    return 0;
}