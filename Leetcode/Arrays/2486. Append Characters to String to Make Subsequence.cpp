/*
You are given two strings s and t consisting of only lowercase English letters.

Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        /*
            c o a c h i n g
    
        
        */

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(NULL);
        
        int i=0,j=0,n=s.size(),m=t.size();
        while(i<n && j<m){
            if(s[i]==t[j]){
                j++;
            }
            i++;
        }

        if(j == m){return 0;}
        return (m-j);
    }
};