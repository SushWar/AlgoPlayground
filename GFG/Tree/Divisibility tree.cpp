/*
* Given a tree with n nodes where n is even. The tree is numbered from 1 to n, has n - 1 edges and is rooted at node 1. 
* Your task is to eliminate the maximum number of edges resulting in a set of disjoint trees where the number of nodes in each tree is divisible by 2.
*/

//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int fixer(int node, int &result, vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        int size = 1;
        
        for(int baccha : adj[node]){
            if(!vis[baccha]){
                int temp = fixer(baccha, result, adj, vis);
                size += temp;
                if(temp % 2 == 0) result++;
            }
        }
        
        return size;
    }
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
	    /*
	        
	    */
	    
	    vector<int>adj[n+1];
	    vector<int>vis(n+1,0);
	    int result=0;
	    
	    for(int i=0;i<edges.size();i++){
	        int u = edges[i][0], v = edges[i][1];
	        
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }
	    
	    for(int i=1;i<=n;i++){
	        if(!vis[i]){
	            int temp = fixer(i,result, adj,vis);
	        }
	    }
	    
	    return result;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends