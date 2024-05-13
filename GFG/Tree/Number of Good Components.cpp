//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

#define pp pair<int,int>
class Solution {
  public:
    pp isComponent(vector<int>&visit,int node, vector<int>adj[]){
        
       visit[node]=1;
       int vertecCount = 1;
       int edgeCount = adj[node].size();
       
       for(int x: adj[node]){
           if(!visit[x]){
               pp temp =  isComponent(visit, x, adj);
               int subTreeVertex = temp.first;
               int subTreeEdge = temp.second;
               vertecCount+=subTreeVertex;
               
               edgeCount+=subTreeEdge;
           }
       }
        
        return make_pair(vertecCount,edgeCount);
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        
        /*
            x**(x-1) => 3 * 2 => 6/2 => 3
            3
            
            1       1 1
            
            1 1       1 1 1
        
        */
        
        vector<int>adj[v];
        
        for(int i=0;i<e;i++){
            int u = edges[i][0]-1, v = edges[i][1]-1;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        vector<int>visit(v,0);
        int counter = 0;
        for(int i=0;i<v;i++){
            if(!visit[i]){
                pp temp = isComponent(visit, i, adj);
                int componentVertices = temp.first;
                int componentEdges = temp.second;
                
                if(componentVertices * (componentVertices-1) == componentEdges){
                    counter++;
                }
                
            }
            
        }
        
        return counter;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends