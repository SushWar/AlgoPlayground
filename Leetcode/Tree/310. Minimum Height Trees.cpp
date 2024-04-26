#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        /*
            0 -> 3
            1 -> 3 
            2 -> 3
            3 -> 0, 1, 2, 4
            4 -> 3, 5
            5 -> 5

            
            0 - 1
            1 - 0, 2, 3
            2 - 1
            3 - 1
            
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int>res;

        if(n==1){
            res.push_back(0);
            return res;
        }

        vector<int>deg(n,0);
        vector<int>adj[n];


        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1];
            deg[u]++;
            deg[v]++;
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        queue<int>order;

        for(int i=0;i<n;i++){
            if(deg[i] == 1){
                order.push(i);
            }
        }

        while(n>2){
            int size = order.size();
            n-= size;
            while(size > 0){
                int go = order.front();
                order.pop();
                for(int node: adj[go]){
                    deg[node]--;
                    if(deg[node] == 1){
                        order.push(node);
                    }
                }
                size--;
            }
        }

        while(!order.empty()){
            int ele = order.front();
            order.pop();
            res.push_back(ele);
        }

        return res;
        
    }
};