#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        
        int n = grid.size(), m = grid[0].size();
        
        int i = 0, j = 0;

       for(int i=0;i<n;i++){
            if(grid[i][0] == 0){
                for(int j=0;j<m;j++){
                    grid[i][j] ^= 1;
                }
            }
       }

       for(int i=1;i<m;i++){
        int countZero = 0;
        for(int j=0;j<n;j++){
            if(grid[j][i] == 0){
                countZero++;
            }
        }

        if(countZero > (n-countZero)){
            for(int j=0;j<n;j++){
                grid[j][i] ^= 1;
            }
        }
       }

        int result = 0;
       for(int i=0;i<n;i++){
        int count = 0;
        int temp = 0;
        for(int j=m-1;j>=0;j--){
            // cout<<grid[i][j]<<" ";
            temp += (grid[i][j] * pow(2, count));
            count++;
        }
        // cout<<endl;
        // cout<<temp<<endl;

        result += temp;
       }



       return result;
    }
};