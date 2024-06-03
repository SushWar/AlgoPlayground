/*
Given a list s that initially contains only a single value 0. There will be q queries of the following types:

0 x: Insert x in the list
1 x: For every element a in s, replace it with a ^ x. ('^' denotes the bitwise XOR operator)
Return the sorted list after performing the given q queries.
*/

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

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
     vector<int> optimizeApproach(int q, vector<vector<int>> &queries){
         
         
        vector<int>result;
        result.emplace_back(0);
        
        for(int i=0;i<q;i++){
            if(!queries[i][0]){
                result.emplace_back(queries[i][1]);
            }
        }
        
        int k=result.size()-1, xorAction = 0;
        
        for(int i=q-1;i>=0;i--){
            if(!queries[i][0]){
                result[k--] ^= xorAction;
            }
            else{
                xorAction ^= queries[i][1];
            }
        }
        result[0] ^= xorAction;
        sort(begin(result),end(result));
        return result;
     }
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        /*
            -> ek list hai and usmai phele sai hi 0 added hai
            -> q queries hai, 
                1. agar 0 hai toh, insert karne ka
                2. agar 1 hai toh, XOR har element ka kar
            
            
            bruteForce 
                -> loop on queris is O(q)
                -> agar 1 hai toh loop again on list size x TC -> O(q*x)
            
            
          
        */
        
        return optimizeApproach(q,queries);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
}

// } Driver Code Ends