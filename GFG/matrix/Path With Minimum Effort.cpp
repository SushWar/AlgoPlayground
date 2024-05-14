//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

#define pp pair<int,pair<int,int>>

class Solution {
   
  public:
    
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        /*
            [1,2,2]
            [3,8,2]
            [5,3,5]
            
        */
        // ios_base::sync_with_stdio(0);
        // cin.tie(0);
        // cout.tie(0);
        
        priority_queue<pp, vector<pp>, greater<pp>>order;
        vector<vector<int>>dist(rows,vector<int>(columns, INT_MAX));
        
        dist[0][0] = 0;
        order.push({0,{0,0}});
        
        int horizontal[] = {1,-1,0,0};
        int vertical[] = {0,0,1,-1};
        while(!order.empty()){
            pp take = order.top();
            order.pop();
            
            int effort = take.first;
            int xAxis = take.second.first;
            int yAxis = take.second.second;
            
            if(xAxis == rows-1 && yAxis == columns-1){return effort;}
            
            for(int i=0;i<4;i++){
                int newRow = xAxis + horizontal[i];
                int newCol = yAxis + vertical[i];
                
                if(newRow >= 0 && newCol >= 0 && newRow < rows && newCol < columns){
                    int newEffort = max(effort, abs(heights[xAxis][yAxis] - heights[newRow][newCol]));
                    if(newEffort < dist[newRow][newCol]){
                        dist[newRow][newCol] = newEffort;
                        order.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends