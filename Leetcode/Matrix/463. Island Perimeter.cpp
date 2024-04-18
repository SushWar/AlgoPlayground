#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int res = 0;
        int n = grid.size(), m=grid[0].size();

        queue<pair<int,int>>order;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    order.push({i,j});
                    
                    break;
                }
            }
        }


        int x[] = {1,-1,0,0};
        int y[] = {0,0,1,-1};
        while(!order.empty()){
            auto take = order.front();
            order.pop();

            int row = take.first;
            int col = take.second;
            if(visited[row][col]){continue;}
            visited[row][col] = 1;

            for(int i=0;i<4;i++){
                int newRow = row + x[i];
                int newCol = col + y[i];
                
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){

                    if(grid[newRow][newCol] == 1){
                        order.push({newRow, newCol});
                    }
                    else{
                        res += 1;
                    }
                }
                else{
                    res += 1;
                }


            }
        }

        return res;
        


        
    }
};