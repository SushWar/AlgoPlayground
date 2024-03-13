//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         
         /*
         https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1
                1 2 3 4 5
                1 2 3 4 5
                1 2 3 4 5
                1 2 3 4 5
                1 2 3 4 5
                
                right->leftDiag->down->rightDiag
                
         */
         
         int i=0,j=0, n=mat.size();
         vector<int>result;
         result.push_back(mat[i][j]);
         while(true){
            if(i==n-1 && j==n-1){break;}
            //right
            if(j+1<n){
                j++;
                while(j>=0 && i<n){
                    result.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                i--;
                j++;
            }
            else{
                i++;
                while(j>=0 && i<n){
                    result.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                i--;
                j++;
            }
            
            if(i+1 < n){
                i++;
                while(i>=0 && j<n){
                    result.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                j--;
                i++;
            }
            else{
                j++;
                while(i>=0 && j<n){
                     result.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                j--;
                i++;
                
            }
            
         }
         
         
         return result;
        
         
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends