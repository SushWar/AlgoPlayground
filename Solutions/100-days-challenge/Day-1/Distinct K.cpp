
#include <bits/stdc++.h>
using namespace std;


int main() {

  /*
    Problem statement :- You wish to help Ashish, who possesses a collection of N strings, some of which may be duplicated, 
    and has been assigned the task of finding the kth unique string.If the number of unique strings is less than k, he needs to display an empty string. 
    Considering you are Ashish's best friend can you assist him with this challenge ? (https://unstop.com/code/challange-asesment/250739?moduleId=372)

    Input format :- The first line contains an integer N denoting the number of strings.
                    The next N lines contain strings.
                    The next line contains an integer k.

    TestCase input :- 
    [
      6
      d
      b
      c
      b
      c
      a
      2
    ]

    TestCase output :-
    [
      a
    ]
  */


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    unordered_map<string,int>order;
    vector<string>finder(n,"");

    for(int i=0;i<n;i++){
      string s1;
      cin>>s1;
      if(order.count(s1)){
        finder[order[s1]] = "";
      }
      else{
        order[s1] = i;
        finder[i] = s1;
      }
    }
    
    int k;
    cin>>k;

    int i=0;
    while(i<n){
      if(finder[i]!= ""){
        k--;
      }
      if(k==0){
        cout<<finder[i]<<endl;
        break;
      }
      i++;
    }
    
    return 0;
}