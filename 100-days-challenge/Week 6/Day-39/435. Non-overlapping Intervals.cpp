/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number 
of intervals you need to remove to make the rest of the intervals non-overlapping.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==0) return 0;

        vector<pair<int,int>> inter(n);

        for(int i=0;i<n;i++){
            inter[i] = {intervals[i][0], intervals[i][1]};
        }

        sort(inter.begin(), inter.end(), [](auto &a, auto &b){return a.second<b.second ;});

        int prevEnd = inter[0].second;
        int result = 0;

        for(int i=1;i<n;i++){
            int newStart = inter[i].first, newEnd = inter[i].second;

            if(newStart < prevEnd){
                result++;
            }
            else{
                prevEnd = newEnd;
            }
        }

        return result;
    }
};