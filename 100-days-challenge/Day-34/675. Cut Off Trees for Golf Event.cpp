#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
class Solution {
public:

   

    int bfs(vector<vector<int>>& forest, int i, int j, int l, int k){
        
        if(i == l && j == k) return 0;
        int n = forest.size() , m = forest[0].size();

        queue<pp>order;
        vector<vector<int>>vis(n,vector<int>(m,0));
        order.push({i,j});

        int step = 0;
        int x[] = {1,-1,0,0};
        int y[] = {0,0,1,-1};

        while(!order.empty()){
            step++;
            int size = order.size();
            for(int t=0;t<size;t++){
                auto take = order.front();
                order.pop();

                int row = take.first;
                int col = take.second;

                for(int i=0;i<4;i++){
                    int nRow = row + x[i];
                    int nCol = col + y[i];

                    if(nRow < 0 || nCol < 0 || nRow >= n || nCol >= m || forest[nRow][nCol]==0 || vis[nRow][nCol])    continue;

                    if(nRow == l && nCol == k){return step;}
                    forest[nRow][nCol] = 1;
                    order.push({nRow,nCol});
                    vis[nRow][nCol]=1;
                }
            }
            
        }

        return -1;
    }
   
    int cutOffTree(vector<vector<int>>& forest) {

        
        if(forest.empty() || forest[0].empty()){
            return 0;
        }

        vector<vector<int>>mark;
        int n = forest.size(), m = forest[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j] > 1){
                    mark.push_back({forest[i][j], i, j});
                }
            }
        }

        sort(mark.begin(),mark.end());
        int res = 0, curr_row = 0, curr_col=0;

        for(int i=0;i<mark.size();i++){
            // clear();
            int get = bfs(forest, curr_row, curr_col, mark[i][1], mark[i][2]);
            if(get == -1){return -1;}
            res += get;
            curr_row = mark[i][1];
            curr_col = mark[i][2];
        }

        return res;

    }
};