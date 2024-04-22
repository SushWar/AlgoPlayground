#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        /*
            "0201","0101","0102","1212","2002"

            0202 -> 0203 -> 0103 -> 0003 -> 0002->0001->0000
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        unordered_set<string>deadlock(begin(deadends), end(deadends));

        if(deadlock.count("0000")) return -1;

        queue<pair<string,int>>order;

        order.push({target, 0});
        int result = INT_MAX;

        
        while(!order.empty()){

            auto take = order.front();
            order.pop();

            string pos = take.first;
            int moves = take.second;

            if(pos == "0000"){
                result = min(result, moves);
                continue;
            }
            // if(deadlocks.count(pos)) continue;

            for(int i=0;i<4;i++){
                
                int add = pos[i]-'0' + 1 <= 9 ? pos[i]-'0' + 1 : 0;
                int sub = pos[i]-'0' - 1 >= 0 ? pos[i]-'0' - 1 : 9;
                string up,down;
                up = down = pos;
                up[i] = add + '0';
                down[i] = sub + '0';
                
                if(!deadlock.count(up)){
                    order.push({up , moves+1});
                    deadlock.insert(up);
                }

                if(!deadlock.count(down)){
                    order.push({down, moves+1});
                    deadlock.insert(down);
                }
            }

        }
        return result == INT_MAX ? -1 : result;
    }
};