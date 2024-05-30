/*
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.

 
*/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        /*
            prefix = 1;

            1 1 = 0
            1 0 = 1
            0 1 = 1
            0 0 = 0

            2,3,1,6,7

            0,1,2 => [2] [3,1]
            0,2,2 => [2,3] [1]
            2,3,4 => [1] [6,7]
            2,4,4 => [1,6] [7]
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = arr.size(); 
        vector<int> prefixXOR(n + 1); 
      
        
        for (int i = 0; i < n; ++i) {
            prefixXOR[i + 1] = prefixXOR[i] ^ arr[i];
        }

        int ans = 0; 

        
        for (int i = 0; i < n - 1; ++i) { 
            for (int j = i + 1; j < n; ++j) { 
                for (int k = j; k < n; ++k) { 

                    
                    int a = prefixXOR[j] ^ prefixXOR[i];
                    
                    int b = prefixXOR[k + 1] ^ prefixXOR[j];

                    
                    if (a == b) {
                        ++ans;
                    }
                }
            }
        }

        
        return ans;
    }
};