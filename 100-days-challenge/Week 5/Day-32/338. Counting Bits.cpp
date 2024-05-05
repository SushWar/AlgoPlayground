#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> countBits(int n) {

        /*
        
            0 - 0
            1 - 1
            2 - 1
            3 - 2
            4 - 1
            5 - 2
            6 - 2
            7 - 3
            8 - 1
            9 - 2
            10 - 2
            11 - 3
            12 - 2
            13 - 3
            14 - 3
            15 - 4
        */

        vector<int>res;

        for(int i=0;i<=n;i++){
            int val = __builtin_popcount(i);
            res.push_back(val);
        }

        return res;
        
    }
};