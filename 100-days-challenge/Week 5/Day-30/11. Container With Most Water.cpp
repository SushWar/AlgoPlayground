#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

        /*
            1,8,6,2,5,4,8,3,7

            i=0, j=8 {1,7} => max(0,min(1,7)*(8-0)) => 8 and i++;
            i=1,j=8 {8,7} => max(8, min(8,7)*(8-1)) => 49 and j--;
        
        */

        int i=0, j=height.size()-1, res = 0;

        while(i<j){
            res = max(res,min(height[i],height[j])*(j-i));
            if(height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }

        return res;
        
    }
};