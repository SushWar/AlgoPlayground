/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent 
the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given 
an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by start
 and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin.tie(NULL);

        vector<vector<int>>result;
        int new_start = newInterval[0], new_end = newInterval[1];
        bool flag = true;
        for(int i=0;i<intervals.size();i++){
            int start = intervals[i][0], end = intervals[i][1];

            if(end < new_start){
                result.push_back({start,end});
            }
            else if(start > new_end){
                if(flag){
                    result.push_back({new_start, new_end});
                    flag = false;
                }
                result.push_back({start,end});
            }
            else{
                new_start = min(new_start, start);
                new_end = max(new_end,end);
            }
        }
        if(flag){result.push_back({new_start,new_end});}
        return result;
    }
};