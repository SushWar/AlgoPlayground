#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        /*
            0,1,0,2,1,0,1,3,2,1,2,1

            i=0, j=11 ==> 0 < 1 ==> res + (0-0);
            i=1, j=11 ==> 1 < 1 ==> res + (1-1);
            i=1, j=10 ==> 1 < 2 ==> res + (1-1);
            i=2, j=10 ==> 1 < 2 ==> res + (1-0) ; => 1
            i=3, j=10 ==> 2 < 2 ==> res + (2-2) ;
            i=3, j=9 ==> 2 < 2 ==> res + (2-1) ; => 1
            i=3, j=8 ==> 2 < 2 ==> res + (2-2) ;
            i=3, j=7 ==> 2 < 3 ==> res + (2-2) ;
            i=4, j=7 ==> 2 < 3 ==> res + (2-1) ; => 1
            i=5 j=7 ==> 2 < 3 ==> res + (2-0) ; => 2
            i=6 j=7 ==> 2 < 3 ==> res + (2-1) ; => 1

            ans = 6
        */

        int i=0, j= height.size()-1, res = 0;
        int left = 0, right = 0;
        while(i<j){
            left = max(left, height[i]);
            right = max(right, height[j]);

            if(left < right){
                res += (left - height[i]);
                i++;
            }
            else{
                res += (right - height[j]);
                j--;
            }
        }

        return res;
    }
};