#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxi(vector<int>fall, int m){

        stack<int>st;
        int ans = 0;
        for(int i=0;i<=m;i++){

            while(!st.empty() && (i==m || fall[st.top()] >= fall[i])){
                int height = fall[st.top()];
                st.pop();
                int width = i;
                if(!st.empty()){
                    width = i - st.top() - 1;
                }
                ans = max(ans , height * width);
            }

            st.push(i);
        }

        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        /*
            1 0 1 0 0 => 
            2 0 2 1 1 => 
            3 1 3 2 2 => 
            4 0 0 3 0 => 
            
            

        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        int n = matrix.size(), m = matrix[0].size();

        vector<int>fall(m,0);
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '0'){
                    fall[j] = 0;
                    continue;
                }
                fall[j]++;
            }
            int val = findMaxi(fall,m);
            res = max(res, val);
        }

        return res;

      
        
    }
};