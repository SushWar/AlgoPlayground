/*
There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. 
You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the 
start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is 
grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        /*
            1,0,1,2,1,1,7,5

            0,1,0,1,0,1,0,1

            prefix sum = 18

        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        int n = grumpy.size();
        int preStaisfy = 0;

        for(int i=0;i<n;i++){
            if(grumpy[i] == 0){
                preStaisfy += customers[i];
            }
        }

        int i=0, j=0, canBeSatisfy = 0, temp = 0;

        while(j< minutes){
            if(grumpy[j] == 1){
                temp += customers[j];
            }
            j++;
        }

        canBeSatisfy = max(canBeSatisfy, temp);
        while(j<n){
            if(grumpy[i] == 1){
                temp -= customers[i];
            }
            if(grumpy[j] == 1){
                temp += customers[j];
            }
            canBeSatisfy = max(canBeSatisfy, temp);
            j++;
            i++;
        }

        return preStaisfy+ canBeSatisfy;
        
    }
};