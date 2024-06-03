/*
Given an array of intervals where intervals[i] = [starti, endi], merge all 
overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        sort(begin(intervals), end(intervals));
        vector<vector<int>>order;
        int n = intervals.size();
        int start = intervals[0][0], end = intervals[0][1];

        for(int i=1;i<n;i++){
            int newStart = intervals[i][0];
            int newEnd = intervals[i][1];

            if(end >= newStart){
                end = max(end,newEnd);
            }
            else{
                order.push_back({start,end});
                start = newStart;
                end = newEnd;
            }
        }

        order.push_back({start,end});

        return order;
    }
};