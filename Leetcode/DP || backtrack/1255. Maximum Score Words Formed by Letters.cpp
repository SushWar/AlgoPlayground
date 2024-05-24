/*
Given a list of words, list of  single letters (might be repeating) and score of every character.

Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).

It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

*/

#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,string>
class Solution {
    int result;
    
public:
    int tempFile(vector<string>& words, vector<char>& letters, vector<int>& score){
        
        int wordSize = words.size();
        int letSize = letters.size();
        priority_queue<pp>order;
        unordered_map<char,int>store;

        for(auto x: letters){
            store[x]++;
        }

        for(int i=0;i<wordSize;i++){
            int temp = 0;
            for(int j=0;j<words[i].size();j++){
                temp += score[words[i][j]-'a'];
            }
            order.push({temp,words[i]});
        }
        
        int result = 0;


        
        
        while(!order.empty() && !store.empty()){
            pp take = order.top();
            order.pop();

            int canBeAdd = take.first;
            string makeWord = take.second;

            bool flag = true;

            for(char x: makeWord){
                if(store[x] > 0){
                    store[x]--;
                    // if(store[x] == 0){store.erase(x);}
                }
                else{
                    flag = false;
                    break;
                }
            }

            if(flag){
                cout<<canBeAdd<<" --> "<<makeWord<<endl;
                result += canBeAdd;
            }
        }
        return result;
    }

    void search(int idx, int n, int currScore,vector<string>& words, vector<int>& preScore, vector<int>alpha){

        if(idx >= n){
            result = max(result, currScore);
            return;
        }

        search(idx+1,n,currScore, words, preScore, alpha);

        bool flag = true;
        for(int i=0;i<words[idx].size();i++){
            int ptr = words[idx][i]-'a';
            if(alpha[ptr]){
                alpha[ptr]--;
            }
            else{
                flag = false;
                break;
            }
        }

        if(flag){
            search(idx+1,n,currScore+preScore[idx], words, preScore, alpha);
        }
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        /*
            a","a","c","d","d","d","g","o","o"


            "dog" - 5+2+3 => 10 
            "cat" - 9+1+0 => 10 
            "dad" - 5+1+5 = > 11
            "good" - 3+2+2+5 => 12


            x - 5
            z - 10
            5+5+5+10 => 25

            4+5 => 9
            4+5 => 9
            4+5 => 9
        */

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        

        int wordSize = words.size();
        int letSize = letters.size();
        result = 0;

        vector<int>alpha(26,0);
        vector<int>preScore(wordSize,0);

         for(int i=0;i<wordSize;i++){
            int temp = 0;
            for(int j=0;j<words[i].size();j++){
                temp += score[words[i][j]-'a'];
            }
            preScore[i] = temp;
        }
        
        for(int i=0;i<letSize;i++){
            alpha[letters[i]-'a']++;
        }

         search(0,wordSize,0, words, preScore, alpha);
        return result;
    }   
};