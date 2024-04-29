#include <bits/stdc++.h>
using namespace std;

class Solution {
    int noOfNodes;
    vector<int>ans,count;
    vector<vector<int>>adj;
public:
    //BRUTE FORCE
    vector<int> bruteForce(int n, vector<vector<int>>& edges){
         vector<int>res(n,0);
        vector<int>adj[n];

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        for(int i=0; i<n;i++){
            int step = helper(adj,n,i);
            res[i]=step;
        }

        return res;
    }
    int helper(vector<int>adj[], int n, int child){
        queue<int>order;

        order.push(child);
        int count = 0;
        int ans = 0;
        vector<int>visit(n,0);
        // cout<<"which --> "<<child<<endl;
        while(!order.empty()){
           int sze = order.size();
           ans += (count * sze);
            // cout<<"ans --> "<<ans<<endl;
           for(int i=0;i<sze;i++){
            int node = order.front();
            order.pop();
            visit[node]=1;
            // cout<<"NODE --> "<<node<<endl;
            for(int parent : adj[node]){
                if(!visit[parent]){
                    // cout<<"PARENT --> "<<parent<<endl;
                    order.push(parent);
                }
            }
           }

           count++;
        }

        return ans;
    }

    //OPTIMAL
    void bottomToUp(int node, int parent){
        for(int child: adj[node]){
            if(child != parent){
                bottomToUp(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void upToBottom(int node, int parent){
        for(int child: adj[node]){
            if(child != parent){
                ans[child] = ans[node] - count[child] + (noOfNodes - count[child]);
                upToBottom(child,node);
            }
        }
    }
    vector<int> optimalAnswer(int n, vector<vector<int>>& edges){
        noOfNodes = n;
        ans.assign(n,0);
        count.assign(n,1);

        adj = vector<vector<int>>(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0], v = edges[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        bottomToUp(0,-1);
        upToBottom(0,-1);
        return ans;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

        /*
          First find the answer for root 0. travel bottom to top
          Second from top to bottom calulate answer for child
        */
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        return optimalAnswer(n,edges);
       

    }
};