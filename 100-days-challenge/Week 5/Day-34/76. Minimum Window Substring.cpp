#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        /*
        

            if(s==t) return s;

            unordered_map<char,int> originalCount;

            for(char alphabet: t){
                originalCount[alphabet]++;
            }
            int sLength = s.size();
            int mini = INT_MAX;
            string res = "";
            for(int i=0;i<sLength;i++){
                if(originalCount.count(s[i])){
                    unordered_map<char,int>duplicate = originalCount;
                    int j = i;
                    while(j<sLength){
                        duplicate[s[j]]--;
                        if(duplicate[s[j]] <= 0) duplicate.erase(s[j]);
                        if(duplicate.empty()){
                            break;
                        }
                        j++;
                    }
                    
                    if(duplicate.empty()){
                        int window = j-i+1;
                        if(window < mini){
                            mini = window;
                            res = s.substr(i,window);
                        }
                    }
                    
                }
                

            }

            return res;
        */

        unordered_map<char,int>order;

        for(char x: t){
            order[x]++;
        }

        int mini = INT_MAX, i=0, j=0, n=s.size(), count = t.size(), mainStart = 0;

        while(j<n){

            if(order[s[j]] > 0){
                count--;
            }

            order[s[j]]--;
            j++;

            while(count==0){
                if(j-i < mini){
                    mainStart = i;
                    mini = j-i;
                }
                order[s[i]]++;
                if(order[s[i]] > 0) {
                    count++;
                }

                i++;
            }
        }

        return mini != INT_MAX ? s.substr(mainStart, mini) : "";
    }
};