#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMaxK(vector<int>& nums) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        

        unordered_map<int,int>order;
        int result = -1;
        for(int x: nums){
            int converter = x*-1;
            if(order.count(converter)){
                result = max(result,abs(converter));
            }
            order[x]++;
        }
        return result;
        
    }
};