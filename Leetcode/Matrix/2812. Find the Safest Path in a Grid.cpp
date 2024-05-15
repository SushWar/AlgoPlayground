#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
#define threePP pair<int,pair<int,int>>

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,-1,1};

class Solution {
public:
    int calculateMinDist(vector<pp>&target, int &tarSize, int &row, int &col, int safe){
        
        for(int i=0;i<tarSize;i++){
            int r = target[i].first, c = target[i].second;

            safe = min(safe, (abs(row-r)+abs(col - c)));
        }

        return safe;
    }

    vector<vector<int>> calculatePrefixSafeFactor(vector<vector<int>>& grid, int n){
        vector<vector<int>>tempGrid = grid;
        queue<threePP>order;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(tempGrid[i][j] == 1){
                    order.push({0,{i,j}});
                    tempGrid[i][j] = 0;
                }
                else{
                    tempGrid[i][j] = INT_MAX;
                }
            }
        }


        while(!order.empty()){
            threePP take = order.front();
            order.pop();

            int prevVal = take.first;
            int row = take.second.first;
            int col = take.second.second;

            for(int i=0;i<4;i++){
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                int distTheif = (abs(row-newRow)+abs(col - newCol)) + prevVal;

                if(newRow >=0 && newCol >=0 && newRow <n && newCol < n && tempGrid[newRow][newCol] > distTheif){
                    tempGrid[newRow][newCol] = distTheif;
                    order.push({distTheif, {newRow,newCol}});
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<tempGrid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return tempGrid;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        /*
            Saffenes factor -> min distance from any cell of the path to any theif 

            return maximum safeness factors
        
            calculatre pre safe factor for every cell 

            0,2, 0,3 => 1
            1,2, 0,3 => 1+1 => 2
            2,1, 0,3 => 2 + 2 => 4 || 2,1, 1,2 => 1+1 => 2+2
            [0,0,0,1]
            [0,0,0,0]
            [0,0,0,0]
            [1,0,0,0]


        */

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]){return 0;}

        vector<vector<int>>newGrid = calculatePrefixSafeFactor(grid,n);
        vector<vector<int>>visit(n,vector<int>(n,0));
        priority_queue<threePP> order;

        order.push({newGrid[0][0],{0,0}});
        visit[0][0] = 1;
        
        while(!order.empty()){
            threePP take = order.top();
            order.pop();

            int safe = take.first;
            int row = take.second.first;
            int col = take.second.second;

            

            if(safe == 0){return 0;}
            if(row == n-1 && col == n-1){return safe;}

            for(int i=0;i<4;i++){
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if(newRow >= 0 && newCol >=0 && newRow <n && newCol < n && !visit[newRow][newCol] && newGrid[newRow][newCol] > 0){
                    visit[newRow][newCol] = 1;
                    int newSafe = min(safe, newGrid[newRow][newCol]);
                    order.push({newSafe, {newRow, newCol}});
                }
            }
        }

        return 0;


    }
};