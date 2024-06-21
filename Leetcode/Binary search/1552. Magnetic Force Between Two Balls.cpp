/*
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls 
if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], 
Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canWeDrop(vector<int>& position, int m, int mid, int n){

        int cnt = 1;
        int i = 1, nextStop = position[0] + mid;
        while(i < n){
            if(position[i] >= nextStop){
                nextStop =  position[i] + mid;
                cnt++;
            }

            i++;
        }

        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        /*
            n = 5, m = 3
            1,2,3,4,7
        */
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n = position.size();
        sort(begin(position),end(position));

        int low = 1, high = position[n-1] - position[0];

        while(low < high){
            int mid = (low + high + 1) >> 1;

            if(canWeDrop(position,m,mid,n)){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }

        
        return low;

    }
};