#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int N) {
    vector<vector<int>>triangle;
    // vector<int>prev(1,1);
    // order.push_back(prev);

    for(int i=0;i<N;i++){
        vector<int> row(i + 1, 1);

        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
        // int size = prev.size();
        // vector<int>curr(size+1);
        
        // for(int j=0;j<size+1;j++){
        //     if(j==0){
        //         curr[j]=prev[0];
        //     }
        //     else if(j == size){
        //         curr[j]=prev[size-1];
        //     }
        //     else{
        //         curr[j] = prev[j-1] + prev[j];
        //     }
        // }
        // order.push_back(curr);
        // prev = curr;
    }

    return triangle;
    }
};

/*
    https://leetcode.com/problems/pascals-triangle/
*/