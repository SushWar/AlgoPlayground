#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void possibleBoth( queue<pair<int,int>>& travel,  vector<vector<bool>>& seen, vector<vector<int>>& heights, int &m, int &n){

        
        int x[] = {1,-1,0,0};
        int y[] = {0,0,1,-1};

        while(!travel.empty()){
            const auto[row,col] = travel.front();
            travel.pop();

            int h = heights[row][col];

            for(int i=0;i<4;i++){
                const int nRow = row + x[i];
                const int nCol = col + y[i];

                if(nRow < 0 || nRow == m || nCol < 0 || nCol == n){continue;}

                if(seen[nRow][nCol] || heights[nRow][nCol] < h) continue;

                travel.push({nRow,nCol});
                seen[nRow][nCol] = true;
            }
        }
    
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        /*
            0,3   0   0   0   0
            0,   0   0   0   0
            0   0   0   0   0
            0   0   0   0   0
            0   0   0   0   0
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        int m = heights.size(), n = heights[0].size();

        queue<pair<int,int>>pacificOrder, atlanticOrder;
        vector<vector<bool>>pacificVisit (m,vector<bool>(n,false));
        vector<vector<bool>>atlanticVisit (m,vector<bool>(n,false));

        for(int i=0;i<m;i++){
            pacificOrder.push({i,0});
            atlanticOrder.push({i,n-1});
            pacificVisit[i][0] = true;
            atlanticVisit[i][n-1] = true;
        }

        for(int i=0;i<n;i++){
            pacificOrder.push({0,i});
            atlanticOrder.push({m-1,i});
            pacificVisit[0][i] = true;
            atlanticVisit[m-1][i] = true;
        }


        possibleBoth(pacificOrder,pacificVisit,heights,m,n);
        possibleBoth(atlanticOrder,atlanticVisit,heights,m,n);


        vector<vector<int>>result;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacificVisit[i][j] && atlanticVisit[i][j]){
                    result.push_back({i,j});
                }
            }
        }

        return result;
    }
};