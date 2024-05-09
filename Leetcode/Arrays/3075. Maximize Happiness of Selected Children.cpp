#include <bits/stdc++.h>
using namespace std;

#define ll long long 
class Solution {
public:
    ll method1(vector<int>& happiness, int k){
        priority_queue<int>order;

        for(int x: happiness){
            order.push(x);
        }

        int counter = 0;
        ll result = 0;
        while(k--){
            int val = order.top();
            order.pop();
            if(val - counter < 0){break;}

            result += (val-counter);
            counter++;
        }

        return result;
    }

    ll method2(vector<int>& happiness, int k){
        sort(begin(happiness),end(happiness));

        int i = happiness.size()-1, counter = 0;

        ll result = 0;

        while(k--){
            int val = happiness[i];
            i--;
            if(val - counter < 0){break;}

            result += (val-counter);
            counter++;
        }

        return result;
    }
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // return method1;

        return method2(happiness, k);
    }
};