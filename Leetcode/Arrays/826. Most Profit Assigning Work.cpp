/*
You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:

difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
Every worker can be assigned at most one job, but one job can be completed multiple times.

For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
Return the maximum profit we can achieve after assigning the workers to the jobs.
*/

#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        

        /*
            4,5,6,7

            {2,10}, {4,20}, {6,30}, {8,40}, {10,50}


        */

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        

        int n = profit.size();

        vector<pp>order;
        for(int i=0;i<n;i++){
            order.push_back({difficulty[i], profit[i]});
        }

        sort(begin(order),end(order));
        sort(begin(worker),end(worker));


        int res = 0, j = 0, getRes = 0;
        for(int x: worker){
            
            while(x >= order[j].first && j<worker.size()){
                getRes = max(getRes, order[j++].second);
            }

            res += getRes;
        }

        return res;

        // priority_queue<pp>order;

        

        // for(int i=0;i<n;i++){
        //     order.push({profit[i],difficulty[i]});
        // }

        // int res = 0;

        // for(int x: worker){

        //     stack<pp>temp;
        //     while(!order.empty()){
        //         pp take = order.top();
        //         order.pop();

        //         temp.push(take);
        //         if(take.second <= x){
        //             res += take.first;
        //             break;
        //         }
        //     }

        //     while(!temp.empty()){
        //         pp take= temp.top();
        //         temp.pop();
        //         order.push(take);
        //     }
        // }

        // return res;
    }
};