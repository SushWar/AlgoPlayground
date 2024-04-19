#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void bfs(int i, int j,vector<vector<int>>&visited, vector<vector<char>>& grid, int n, int m){
        
        queue<pair<int,int>>order;
        order.push({i,j});

        int x[] = {1,-1,0,0};
        int y[] = {0,0,1,-1};
        while(!order.empty()){
            auto take = order.front();
            order.pop();

            int row = take.first;
            int col = take.second;

            if(visited[row][col]) continue;

            visited[row][col] = 1;
            
            for(int i=0;i<4;i++){
                int nRow = row + x[i];
                int nCol = col + y[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol] && grid[nRow][nCol] == '1'){
                    
                    order.push({nRow,nCol});
                }
            }
        }
    }
   
    int numIslands(vector<vector<char>>& grid) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n=grid.size(), m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        int islands = 0;


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    bfs(i,j,visited,grid,n,m);
                    islands++;
                }
            }
        }


        

       

        return islands;
    }
};