/*
Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

If the current number is even, you have to divide it by 2.

If the current number is odd, you have to add 1 to it.

It is guaranteed that you can always reach one for all test cases.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
         ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(NULL);


        int steps = 0;
        while(s != "1"){
            if(s.back() == '0'){
                s.pop_back();
                steps++;
            }
            else{
               while(!s.empty() && s.back()=='1'){
                   steps++;
                   s.pop_back();
               }
               if(s.empty()){
                   s = "1";
                   steps++;
                   return steps;
               }
               s.back() = '1';
               steps++;
            }
        }
        return steps;
    }
};