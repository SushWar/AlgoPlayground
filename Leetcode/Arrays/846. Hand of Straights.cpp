/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
 */
#include<bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        /*
            1. cards given hai
            2. rearrange cards into groups of size groupSize
            3. Consecutive hone chaiye

            hand = [1,2,3,6,2,3,4,7,8], groupSize = 3

            {1,1} {2,2} {3,2} {4,1} {6,1} {7,1} {8,1}

        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);



        int n = hand.size();

        if(n%groupSize != 0){return false;}

        unordered_map<int,int>freq;

        for(int x: hand){
            freq[x]++;
        }


        priority_queue<pp, vector<pp>, greater<pp>>order;

        for(auto x: freq){
            order.push({x.first, x.second});
        }


        int last = -1, timer = 0;
        queue<pp>store;
        while(!order.empty()){
            pp take = order.top();
            order.pop();

            if(last == -1 || last + 1 == take.first){
                last = take.first;
                timer++;
                if(take.second-1 > 0) store.push({take.first, take.second-1});
            }
            else if(last + 1 != take.first){
                return false;
            }

            if(timer == groupSize){
                last = -1;
                timer = 0;
                while(!store.empty()){
                    pp pick = store.front();
                    store.pop();
                    order.push(pick);
                }
            }
        }
        
        if(!store.empty()) return false;
        return true;

    }
};