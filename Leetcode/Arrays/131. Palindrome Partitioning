/*
Given a string s, partition s such that every 
substring
 of the partition is a 
palindrome
. Return all possible palindrome partitioning of s.

 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
vector<vector<string>>result;
public:
    bool palindrome(string t, int i, int j){
        if(t.size()==0){return false;}
        if(t.size()==1){return true;}
        while(i<j){
            if(t[i] != t[j]){return false;}
            i++;
            j--;
        }
        return true;
    }
   
  void help(string s, int idx, vector<string>&put, int n){
      if(idx == n){
          if(put.size()>0){
              result.emplace_back(put);
          }
          return ;
      }

      for(int i=idx;i<n;i++){
          if(palindrome(s,idx,i)){
              put.emplace_back(s.substr(idx,i-idx+1));
              help(s,i+1,put,n);
              put.pop_back();
          }
      }
  }
   
    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(NULL);
        int n = s.size();
        vector<string>put;
        help(s,0,put,n);
        return result;
    }
};