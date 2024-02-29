#include <bits/stdc++.h>
using namespace std;
vector<int>store(100001, 0);

int helper(int x){

  int counter = 0;
  x -= 2;
  while(x > 0){
    if(store[x] > 0){
      counter += store[x];
    }
    else{
      int temp = 0, tempX = x;
      while(tempX > 0){
        temp += tempX;
        tempX--;
      }
      counter += temp;
      store[x] = temp;
    }
    x--;
  }

  return counter;
}


int main() {
    /* https://unstop.com/code/challange-asesment/250281?moduleId=410
    
      1 1 1 1 1 1

      3 => 1
      4 => (4)  2+1=>3
                1=>1    
      5 => (10) 3+2+1 => 6
                2+1 => 3
                1 => 1 
      6 =>(20)  4+3+2+1 => 10
                3+2+1 => 6
                2+1 => 3
                1 => 1
    */   

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    unordered_map<int,int>counter;

    for(int i=0;i<n;i++){
      int sock;
      cin>>sock;

      counter[sock]++;
    }

    int result = 0;

    for(auto x: counter){
        if(x.second >= 3){
          result += helper(x.second);
        }
    }

    cout<<result<<endl;


    return 0;
}