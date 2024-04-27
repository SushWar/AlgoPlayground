#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<string>>res;
public:
    void fill(int row, int pos, vector<vector<int>>&board, int v){
        
        int n = board.size();
        int tempRow = row+1, tempPos = pos;
        while(tempRow < n){
            board[tempRow][tempPos] += v;
            tempRow++;
        }

        tempRow = row+1, tempPos = pos-1;

        while(tempRow < n && tempPos >= 0){
            board[tempRow][tempPos] += v;
            tempRow++;
            tempPos--;
        }

        tempRow = row+1, tempPos = pos+1;

         while(tempRow < n && tempPos < n){
            board[tempRow][tempPos] += v;
            tempRow++;
            tempPos++;
        }

    }
    void reccur(int idx, int n, vector<vector<int>>board){

        //base
        if(idx == n){
            vector<string>onBoard;
            for(int i=0;i<n;i++){
                string queen = "";
                for(int j=0;j<n;j++){
                    if(board[i][j] == 1){
                        queen+='Q';
                    }
                    else{
                        queen+='.';
                    }
                }
                onBoard.push_back(queen);
            }
            res.push_back(onBoard);
            return;
        }

        //backtrack
        for(int i=0;i<n;i++){
            if(board[idx][i] < 0) continue;

            board[idx][i] = 1;
            fill(idx, i, board, -1);
            reccur(idx+1,n,board);
            fill(idx, i, board, 1);
            board[idx][i] = 0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {

        /*
            . Q . .
            . . . Q
            Q . . .
            . . Q .

            0,1 -> 1 col and [{1,0},{1,2}, {2,3}]
        
        */
        vector<vector<int>>board(n,vector<int>(n,0));
        

        reccur(0,n,board);

        
        return res;
    }
};