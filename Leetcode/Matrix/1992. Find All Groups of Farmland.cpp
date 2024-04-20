#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bfs(int i, int j, int n, int m, vector<vector<int>>&land, vector<vector<int>>&visited){

        vector<int>ans = {i , j};
        queue<pair<int,int>>order;
        order.push({i,j});

        int x[] = {1,-1,0,0};
        int y[] = {0,0,1,-1};
        pair<int,int>last;
        while(!order.empty()){
            auto take = order.front();
            order.pop();

            int row = take.first;
            int col = take.second;

            if(visited[row][col]) continue;

            visited[row][col] = 1;
            last = {row, col};

            for(int i=0;i<4;i++){
                int nRow = row + x[i];
                int nCol = col + y[i];

                if(nRow >= 0 && nCol >= 0 && nRow < n && nCol < m && land[nRow][nCol] && !visited[nRow][nCol]){
                    order.push({nRow,nCol});
                }
            }
        }

        ans.push_back(last.first);
        ans.push_back(last.second);

        return ans;

    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        
        int n = land.size(), m = land[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>result;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j] == 1 && !visited[i][j]){
                    vector<int>cord = bfs(i,j,n,m,land,visited);
                    result.push_back(cord);
                }
            }
        }

        return result;


    }
};