#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        /*

            3
            3/2 => 1

        */
        
       
       vector<int>binaryNum(32,0);
        int i = 0;
        uint32_t res = 0;
        while (n > 0) {

            // storing remainder in binary array
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }

        for(int i=31;i>=0;i--){
            if(binaryNum[i] == 1 ) res += pow(2,(31-i));
        }

        // cout<<pow(7,2);
        return res;
    }
};