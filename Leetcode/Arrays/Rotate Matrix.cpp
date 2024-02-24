#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[j][i],matrix[i][j]);
            }
        }

        for(int i=0;i<n;i++){
            reverse(begin(matrix[i]), end(matrix[i]));
        }
        return ;
    }
};

/*
    https://leetcode.com/problems/rotate-image/
*/