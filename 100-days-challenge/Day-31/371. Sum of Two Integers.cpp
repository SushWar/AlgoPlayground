#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        /*
        
            * /
            & | ^ ~ >> <<

           01
           10

        */

        // int tempXor = a^b;
        // int carry = a&b;
        // carry <<= 1;
        // tempXor = tempXor ^ carry;
        // return tempXor;
        while (b=(~(a^=b)&b)<<1); 
        return a;

        // return log10(pow(10,a)*pow(10,b));
    }
};