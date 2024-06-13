/*
There are n seats and n students in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. You are also given the array students of length n, where students[j] is the position of the jth student.

You may perform the following move any number of times:

Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1)
Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

Note that there may be multiple seats or students in the same position at the beginning.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        /*
            1 3 5
            2 4 7

            1 + 1+ 2 = 4


            1 4 5 9
            1 2 3 6

            0 2 + 2+ 3 
        */

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        

        sort(begin(seats),end(seats));
        sort(begin(students),end(students));

        int res = 0;

        for(int i=0;i<seats.size();i++){
            res += abs(seats[i] - students[i]);
        }

        return res;


    }
};