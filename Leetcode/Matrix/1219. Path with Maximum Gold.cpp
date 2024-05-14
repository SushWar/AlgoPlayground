#include <bits/stdc++.h>
using namespace std;

const int x[] = {1,-1,0,0};
const int y[] = {0,0,1,-1};

class Solution {
    int result;
    bool visited[15][15] {};
public:
    // void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int val, vector<vector<int>>&visit){
    //     // if(i<0 || j<0 || i>=n || j>=m){
    //     //     result = max(result, val);
    //     //     return;
    //     // }

    //     // visit[i][j] = 1;
        
    //     // dfs(i+1,j,n,m,grid,val,visit);
    //     // dfs(i-1,j,n,m,grid,val,visit);
    //     // dfs(i,j+1,n,m,grid,val,visit);
    //     // dfs(i,j-1,n,m,grid,val,visit);
        
    //     for(int k=0;k<4;k++){
    //         int newRow = i+x[k];
    //         int newCol = j+y[k];
    //         if(newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && grid[newRow][newCol] > 0 && !visit[newRow][newCol]){
    //             visit[newRow][newCol] = 1;
    //             val += grid[newRow][newCol];
    //             // cout<<"{VAL,Grid[i][j]} --> "<<val<<" - "<<grid[newRow][newCol]<<endl;
    //             result = max(result, val);
    //             dfs(newRow, newCol, n,m,grid,val,visit);
    //             val -= grid[newRow][newCol];
    //             visit[newRow][newCol] = 0;
    //         }
            
    //     }

    //     return;
    // }

    int dfs2(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=n || j>=m || !grid[i][j] || visited[i][j]){return 0;}

        visited[i][j] = true;
        int gold = 0;
        for(int k=0;k<4;k++){
            gold = max(gold, dfs2(i+x[k], j+y[k], n , m, grid));
        }

        visited[i][j] = false;
        return gold + grid[i][j];

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        /*
                Let's try searching from cell which is not empty
                [0,0,34,0,5,0,7,0,0,0]
                [0,0,0,0,21,0,0,0,0,0]
                [0,18,0,0,8,0,0,0,4,0]
                [0,0,0,0,0,0,0,0,0,0]
                [15,0,0,0,0,22,0,0,0,21]
                [0,0,0,0,0,0,0,0,0,0]
                [0,7,0,0,0,0,0,0,38,0]
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


        int n = grid.size(), m=grid[0].size();
        // result = 0;
        int gold = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] > 0){
                    // vector<vector<int>>visit(n,vector<int>(m,0));
                    // visit[i][j]=1;
                    // result = max(result, grid[i][j]);
                    // dfs(i,j,n,m,grid,grid[i][j],visit); 
                    // Gave 157ms

                    gold = max(gold, dfs2(i,j,n,m,grid));
                }
            }
        }

        // return result;
        return gold;



    }
};