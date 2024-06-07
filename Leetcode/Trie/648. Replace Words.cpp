/*
    In English, we have a concept called root, which can be followed by some other word to form another longer word - let's 
    call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the 
sentence with the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {

    TrieNode* child[26];
    bool isEnd = false;


    bool containsKey(char word){
        return child[word-'a'] != NULL;
    }

    void insert(char word, TrieNode* node){
        child[word-'a'] = node;
    }

    TrieNode* get(char word){
        return child[word-'a'];
    }

    void setEnd(){
        isEnd = true;
    }
    bool hasEnd(){
        return isEnd;
    }
};

class Book{

    TrieNode* root;

    public:

        Book(){
            root = new TrieNode();
        }

        void insert(string word){

            TrieNode* temp = root;
            for(int i=0;i<word.size();i++){
                
                if(!temp->containsKey(word[i])){
                    temp->insert(word[i], new TrieNode());
                }

                temp = temp->get(word[i]);

            }

            temp->setEnd();
        }

        string replacement(string word){
            TrieNode* temp = root;
            string result = "";
            for(int i=0;i<word.size();i++){
                
                if(temp->hasEnd()){
                    return result;
                }
                result += word[i];
                if(!temp->containsKey(word[i])){break;}
                temp = temp->get(word[i]);
            }

            return "-1";
        }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        /*

        */  

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


        Book finder;

        for(string x: dictionary){
            finder.insert(x);
        }

        string result = "", temp = "";

        for(auto x: sentence){
            if(x == ' ' && temp.size() > 0){
                string check = finder.replacement(temp);
                if(check != "-1") result += check + ' ';
                else result += temp + ' ';
                temp = "";
            }
            else{
                temp += x;
            }
        }

        if(temp.size() > 0){
           string check = finder.replacement(temp);
            if(check != "-1") result += check + ' ';
            else result += temp;
        }

        while(result.back() == ' ') result.pop_back();
        return result;
    }
};