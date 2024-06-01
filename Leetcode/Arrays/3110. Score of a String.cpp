/*
You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

Return the score of s.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        int result = 0;

        for(int i=1;i<s.size();i++){
            result += abs(s[i] - s[i-1]);
        }

        return result;
    }
};