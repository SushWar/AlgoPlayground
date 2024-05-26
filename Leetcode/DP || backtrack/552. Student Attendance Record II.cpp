/*
An attendance record for a student can be represented as a string where each character signifies whether the student was absent, late, 
or present on that day. The record only contains the following three characters:

'A': Absent.
'L': Late.
'P': Present.
Any student is eligible for an attendance award if they meet both of the following criteria:

The student was absent ('A') for strictly fewer than 2 days total.
The student was never late ('L') for 3 or more consecutive days.
Given an integer n, return the number of possible attendance records of length n that make a student eligible for an attendance award. 
The answer may be very large, so return it modulo 109 + 7.
*/


#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
class Solution {
    int result;
public:
   

    int checkRecord(int n) {
        /*
            1. ek string hai jo student ki attendance batati hai 
            2. A,P,L hi use kar sakte hai 
            3. attendance award sirf 2 condition par milega 
                1. absent hoga toh sirf 2 day sai neache
                2. student late nahi hua 3 or more consecutive day 
            

            n given hai, aur possible attendance record banao jismai baccha eligible hai attendance award kai liye

            n=2
            A,L,P

            AA 
            AL
            AP
            LA
            LL
            LP
            PA
            PL
            PP

        */
        //total status
        //0: 0A 0L
        //1: 0A 1L
        //2: 0A 2L
        //3: 1A 0L
        //4: 1A 1L
        //5: 1A 2L

        long int dp[6] = {1,0,0,0,0,0}; //at 0 day there is 0A0L
        long int tmp[6];
        const long long mod=1e9+7;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<6;j++)tmp[j] = dp[j];

            //NOW STATE-|-------  NEXT STATE ---------|
            //0: 0A 0L => P: 0A0L    A: 1A0L   L: 0A1L
            //1: 0A 1L => P: 0A0L    A: 1A0L   L: 0A2L
            //2: 0A 2L => P: 0A0L    A: 1A0L   L: X
            //3: 1A 0L => P: 1A0L    A: X      L: 1A1L
            //4: 1A 1L => P: 1A0L    A: X      L: 1A2L
            //5: 1A 2L => P: 1A0L    A: X      L: X
            //    every turn
            //0A0L =0+1+2
            //0A1L =0
            //0A2L =1
            //1A0L =0+1+2+3+4+5
            //1A1L =3
            //1A2L =4

            dp[0] =(tmp[0]+tmp[1]+tmp[2])%mod;
            dp[1] =(tmp[0])%mod;
            dp[2] =(tmp[1])%mod;
            dp[3] = (tmp[0] + tmp[1] + tmp[2] + tmp[3] + tmp[4] +tmp[5])%mod;
            dp[4] =(tmp[3])%mod;
            dp[5] =(tmp[4])%mod;
        }
        
        return (dp[0]+dp[1]+dp[2]+dp[3]+dp[4]+dp[5])%mod;


    }
};