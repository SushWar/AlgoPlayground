/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
 */

 #include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
class Solution {
public:
    bool canWeMake(vector<int>& bloomDay, int m, int k, int day){

        int total = 0;
        for(int i=0;i<bloomDay.size();i++){
            int cnt = 0;
            while(i<bloomDay.size() && cnt<k && bloomDay[i] <= day){
                cnt++;
                i++;
            }

            if(cnt == k){total++; i--;}

            if(total >= m) return true;
        }

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        /*
            1. m bouqet banane hai and k adjacent flower use karne hai. ek flower ek bouqet mai
            2. har flower bloom hoga bloomDay[i] day mai
            
            result => kitn edin lagengey boquet banane mai otherwise -1;

        */
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n = bloomDay.size();

        if((long long)m*k > n) return -1;


        int low = 1, high = 1e9;

        while(low < high){
            int mid = low + (high-low)/2;

            if(canWeMake(bloomDay, m,k,mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }

};