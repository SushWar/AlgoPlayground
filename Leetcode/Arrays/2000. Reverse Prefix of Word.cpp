#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        for(int i=0;i<word.size();i++){
            if(word[i] == ch){
                reverse(word.begin(), word.begin()+i+1);
                break;
            }
        }

        return word;
    }
};