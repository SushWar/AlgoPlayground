#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        /*
            1           2
            0.5

            1,2         3
            0.3

            1,2,3       5
            0.2
        */ 

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        

        auto compare = [&](const pp& a, const pp& b){
            return arr[a.first] * arr[b.second] > arr[a.second] * arr[b.first];
        };

        priority_queue<pp, vector<pp>, decltype(compare)> order(compare);

        for(int i=1;i<arr.size();i++){
            order.push({0,i});
        }


        // while(!order.empty()){
        //     pp take = order.top();
        //     order.pop();

        //     cout<<take.first<<"  -> "<<take.second<<endl;
        // }

        for(int i=1;i<k;i++){
            pp take = order.top();
            order.pop();

            if(take.first + 1 < take.second){
                order.push({take.first+1, take.second});
            }
        }

        return {arr[order.top().first], arr[order.top().second]};

        
    }
};