#include <bits/stdc++.h>
using namespace std;

#define pp pair<double,int>
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        /*
            10,20,5
            70,50,30            
            
            1 => ratio = calculate wage/quantity, every wokrer
            2 => sort 
            3 => minheap
            4 => tots += quanity , add quantity in queue , k==queue.size() => res = min(res, ratio), tots -= queue.top();, queue.pop()
        */

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = quality.size();
        vector<pp>store;

        for(int i=0;i<n;i++){
            store.push_back({(double)wage[i]/quality[i], quality[i]});
        }

        sort(begin(store),end(store));

        priority_queue<int>order;
        double res = 1e9;
        int countQuality = 0;

        for(auto[ratio, quality]: store){
            countQuality += quality;
            order.push(quality);

            if(k == order.size()){
                res = min(res ,ratio *  countQuality);
                countQuality -= order.top();
                order.pop();
            }
        }

        return res;
        
    }
};