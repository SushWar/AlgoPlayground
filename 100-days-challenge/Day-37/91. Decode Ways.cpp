#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        
         int n = s.size();
        int prev2=0, prev1=1,curr;
        
        for(int i=n-1;i>=0;i--){
            int one=0, two=0;
            if(s[i]!='0'){one =prev1;}
            if(i+1<n &&(s[i]=='1' || s[i]=='2' && s[i+1]<'7')){two = prev2;}
            curr = one + two;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};