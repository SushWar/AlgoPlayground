/*
Given a string array words, return an array of all characters that show up in all strings within the words (including duplicates). 
You may return the answer in any order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> count(string s1){
        vector<int>freq(26,0);

        for(auto x: s1){
            freq[x-'a']++;
        }

        return freq;
    }

    vector<int>compare(vector<int>temp, vector<int>curr){
        vector<int>response(26,0);

        for(int i=0;i<26;i++){
            response[i] = min(temp[i], curr[i]);
        }

        return response;
    }
public:
    vector<string> commonChars(vector<string>& words) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int>alpha(26,0);

        int n = words.size();
        vector<int>temp = count(words[0]);
        for(int i=1;i<n;i++){
            temp = compare(temp, count(words[i]));
        }

        vector<string>result;
        for(int i=0;i<26;i++){
            while(temp[i] > 0){
                result.push_back(string(1, 'a'+i));
                temp[i]--;
            }
        }
      

        return result;
    }
};