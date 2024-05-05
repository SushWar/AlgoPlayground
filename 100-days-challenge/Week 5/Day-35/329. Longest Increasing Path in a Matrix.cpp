#include <bits/stdc++.h>
using namespace std;

class Solution {
    int visit[200][200]{};
public:
    bool canWeGo(int row, int col ,int n , int m){
        if(row < 0 || col < 0 || row >= n || col >= m){
            return true;
        }
        return false;
    }

    int dfs(int row, int col ,vector<vector<int>>& matrix,int prev){

        int n = matrix.size(), m=matrix[0].size();
        if(row < 0 || col < 0 || row >= n || col >= m || matrix[row][col] <= prev) return 0;

        if(visit[row][col]){
            return visit[row][col];
        }
        
        int up = dfs(row+1,col,matrix,matrix[row][col]);
        int down = dfs(row-1,col,matrix,matrix[row][col]);
        int right = dfs(row,col+1,matrix,matrix[row][col]);
        int left =  dfs(row,col-1,matrix,matrix[row][col]);
        

        
        return visit[row][col] = 1 + max({up,down,left,right});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        /*
            9,0     |  9,0              | 4,0 , 4,9
            6,9     |  6,9              | 8,0
            2,6,9   | 1,2,6,9 ? 1,6,9   | 1,8



            3,0     |   3,4 ? 4,0   |  
            
        */
        int n = matrix.size(), m = matrix[0].size();
        // visit.assign(n,vector<int>(m,-1));
        vector<vector<int>>preCompted(n,vector<int>(m,0));

        int result = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                result = max(result,dfs(i,j,matrix,-1));
                // cout<<step<<" || ";
                // preCompted[i][j] = max(preCompted[i][j], step);
                // result = max(result, preCompted[i][j]);
            }
            // cout<<endl;
        }

        return result;
    }   
};