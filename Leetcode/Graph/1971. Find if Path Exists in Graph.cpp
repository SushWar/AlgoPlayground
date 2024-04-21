#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(int src, int dest, vector<int>adj[], int n){

        queue<int>order;
        vector<int>visit(n ,0);
        order.push(src);

        while(!order.empty()){
            int go = order.front();
            order.pop();

            if(dest == go) return true;

            if(visit[go]) continue;

            visit[go] = 1;

            for(int x: adj[go]){
                if(!visit[x]){
                    order.push(x);
                }
            }
        }

        return false;

    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

    
        return helper(source,destination,adj, n);
    }
};