#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    
    int numRescueBoats(vector<int>& people, int limit) {

        /*
            1 2 2 3   limit = 3
        */

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        

        sort(begin(people),end(people));

        int i =0, j=people.size()-1;
        int currCap = 0, count = 0;
        while(i<=j){
            currCap = 0;

            if(i<=j){
                currCap += people[j];
                j--;
            }

            if(i<=j && currCap + people[i] <= limit){
                currCap += people[i];
                i++;
            }

            count++;
            currCap = 0;           
        }

        return count;
        
    }
};