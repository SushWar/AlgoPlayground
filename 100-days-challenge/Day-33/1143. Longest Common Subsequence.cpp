#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {


     /*
            a b c d e
        a   1 1 1 1 1
        c   1 1 2 2 2
        e   1 1 2 2 3


     */   

     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);

     

     int n = text1.size(), m = text2.size();
     if(text1==text2) return n;
     vector<int>prev(n,0), curr(n,0);

     for(int i=0;i<n;i++){
        if(text2[0] == text1[i]){
            prev[i] = 1;
        }
        else{
            prev[i] = i > 0 ? prev[i-1] : 0;
        }
        // cout<<prev[i]<<" ";
     }

     for(int i=1;i<m;i++){
        // cout<<endl;
        for(int j=0;j<n;j++){
            if(text2[i] == text1[j]){
                curr[j] = j > 0 ? 1+ prev[j-1] : 1;
            }
            else{
                curr[j] = j > 0 ? max(curr[j-1], prev[j]): prev[j];
            }

            // cout<<curr[j]<<" ";
        }
        prev = curr;
     }
     return prev[n-1];
    }
};