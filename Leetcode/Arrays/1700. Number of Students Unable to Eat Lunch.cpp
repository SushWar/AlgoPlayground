#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
         
         /*
            
            1,1,1,0,0,1   1,0,0,0,1,1
            1,1,0,0,1   0,0,0,1,1
            1,0,0,1,1   0,0,0,1,1
            0,0,1,1,1   0,0,0,1,1
            0,1,1,1   0,0,1,1
            1,1,1   0,1,1

            1,1,1,0,0,1   0,0,0,1,1,1
            3 2 1           3 3
            
         */

        vector<pair<int,int>>count;
        int counter = 1, prev = sandwiches[0], n = sandwiches.size();
         for(int i=1;i<n;i++){
            if(sandwiches[i] == prev){
                counter++;
            }
            else{
                count.push_back({prev, counter});
                counter = 1;
                prev = sandwiches[i];
            }
        }
        count.push_back({prev, counter});

        unordered_map<int,int>order;
        for(int x: students) order[x]++;
        bool failed = false;
        int res = 0;

        for(auto x: count){
            if(failed){
                res += x.second;
                continue;
            }
            if(order[x.first] < x.second){
                res += (x.second - order[x.first]);
                failed = true;
            }
            else{
                order[x.first] -= x.second;
            }
        }

        return res;

    }
};