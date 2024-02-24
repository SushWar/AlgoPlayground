#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n=matrix.size(), m=matrix[0].size();
        set<pair<char,int>>order;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    order.insert({'r',i});
                    order.insert({'c',j});
                }
            }
        }

        for(auto p: order){
            if(p.first == 'r'){
                for(int i=0;i<m;i++){
                    matrix[p.second][i]=0;
                }
            }
            else{
                for(int i=0;i<n;i++){
                    matrix[i][p.second] = 0;
                }
            }
        }
    }
};

/*
    https://leetcode.com/problems/set-matrix-zeroes/
*/