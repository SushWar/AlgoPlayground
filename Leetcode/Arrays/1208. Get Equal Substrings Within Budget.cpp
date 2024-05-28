/*
You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., 
the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost 
less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(NULL);

        int sum = 0,l=0,r=0;
        while(r<s.size()){
            sum += abs(s[r]-t[r++]);
            if(sum > maxCost){
                sum -= abs(s[l]-t[l++]);
            }
        }
        return r-l;
    }
};