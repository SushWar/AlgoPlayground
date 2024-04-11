#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

    /*
        17,13,11,2,3,5,7

        2,3,5,7,11,13,17,
        
        2,13,3,11,5,17,7
        3,11,5,17,7,13
        5,17,7,13,11
        7,13,11,17
        11,17,13
        13,17
        17


        2,3,5,7,11,13,17,18
        
        2,11,3,17,5,13,7,18
        3,17,5,13,7,18,11
        5,13,7,18,11,17
        7,18,11,17,13
        11,17,13,18
        13,18,17
        17,18
        18
       
    */   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sort(begin(deck),end(deck));
    int n = deck.size();
    
    if(n <= 2) return deck;

    deque<int>prev,curr;

    prev.push_back(deck[n-1]);

    for(int i=n-2;i>=0;i--){
        
        int backEle = prev.back();
        prev.pop_back();
        curr.push_back(deck[i]);
        curr.push_back(backEle);

        while(!prev.empty()){
            int ele = prev.front();
            prev.pop_front();
            curr.push_back(ele);
        }

        prev = curr;
        curr.clear();

    }

    vector<int>res;

        while(!prev.empty()){
            int ele = prev.front();
            prev.pop_front();
            res.push_back(ele);
        }

        return res;
    }
};