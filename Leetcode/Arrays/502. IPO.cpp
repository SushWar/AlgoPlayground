/*
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on 
some projects to increase its capital before the IPO. Since it has limited resources, it can only finish at most k distinct projects before the IPO.
 Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.

You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.

Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.

Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.
*/

#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
class Solution {
    int result;
public:
   
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        /*
            {0,1}, {1,2}, {1,3}

            1+2+3 = 6
        */
        
        int n = profits.size();
        vector<pp>proj;

        for(int i=0;i<n;i++){
            proj.emplace_back(capital[i], profits[i]);
        }

        sort(begin(proj),end(proj));
        priority_queue<int>order;

        int idx = 0;
        for(int j=0;j<k;j++){
            while(idx < n && proj[idx].first <= w){
                order.push(proj[idx].second);
                idx++;
            }

            if(order.empty()){break;}

            w += order.top();
            order.pop();
        }

        
        return w;


    }
};