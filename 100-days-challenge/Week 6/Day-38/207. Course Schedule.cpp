#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            1 -> 0
            0 1
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        int n = numCourses;
        vector<int>inDegree(n,0);
        vector<int>graph[n];
        for(int i=0;i<prerequisites.size();i++){
            int before = prerequisites[i][1], after = prerequisites[i][0];
            graph[before].push_back(after);
            inDegree[after]++;
        }

        vector<int>result;
        queue<int>order;

        for(int i=0;i<n;i++){
            if(inDegree[i] == 0){
                order.push(i);
            }
        }

        while(!order.empty()){
            int take = order.front();
            order.pop();

            result.push_back(take);

            for(int node: graph[take]){
                inDegree[node]--;
                if(inDegree[node] == 0){
                    order.push(node);
                }
            }
        }

        return result.size() == n;


    }
};