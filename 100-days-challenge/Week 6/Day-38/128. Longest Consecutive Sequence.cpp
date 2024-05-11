#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
      /*

      */
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      

       unordered_set<int>store;
        for(int x:nums){
            store.insert(x);
        }   

        int res = 0;
        for(auto it: store){
           if (store.find(it - 1) == store.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (store.find(x + 1) != store.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            res = max(res, cnt);
            }
        }


        return res;
       
    }
};