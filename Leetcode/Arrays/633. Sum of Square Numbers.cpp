/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
class Solution {
public:
    
    bool judgeSquareSum(int c) {
        
        /*
            a + b = 5
            a = sqrt 5-b


            1+4 = 5
            1+9 = 10
            1+16 = 17
            1+25 = 26


            4+9 = 13
            4+16 = 20
            4+25 = 29

            9+16 = 25

            5,10,13,17,20,25,26,29

            1 2 3 4 5
        */

        ll low = 0, high = sqrt(c);

        while(low <= high){
            if(low*low + high*high == c) return true;
            if(low*low + high*high > c) high--;
            else low++;
        }
        return false;





       
    }
};