#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        int n = score.size();

        vector<pair<int,int>>shuffle(n);

        for(int i=0;i<n;i++){
            shuffle[i] = {score[i], i};
        }

        sort(begin(shuffle),end(shuffle),greater<pair<int,int>>());

        vector<string>result(n);

        for(int i=0;i<n;i++){
            int idx = shuffle[i].second;
            switch (i) {
                case 0:
                    result[idx] = "Gold Medal";
                    break;
                case 1:
                    result[idx] = "Silver Medal";
                    break;
                case 2:
                    result[idx] = "Bronze Medal";
                    break;
                default:
                    result[idx] = to_string(i+1);
                    break;
            }
        }

        return result;
    }
};