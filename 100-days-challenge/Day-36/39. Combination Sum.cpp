#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>>ans;
public:
    void reccur(int idx, int n, vector<int>candidates, vector<int>temp,int currSum, int target){

        //base
        if(currSum == target){
            ans.push_back(temp);
            return;
        }

        if(currSum > target){return;}

        //choice
        for(int i=idx;i<n;i++){
            temp.push_back(candidates[i]);
            currSum += candidates[i];
            reccur(i,n,candidates,temp,currSum,target);
            currSum -= candidates[i];
            temp.pop_back();
        }

        



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

     /*
        like coin change problem 

            0 1 2 3 4 5 6 7
        2   
        2   
        3   
     */   
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        ans.clear();
        // sort(begin(candidates),end(candidates));
        int idx = 0, n = candidates.size();
        vector<int>temp;
        reccur(idx, n,candidates, temp,0, target);

       
        return ans;

    }
};