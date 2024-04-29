#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string createBinary(int prefix){

        string res ="";

        while(prefix){
            res += (prefix%2)+'0';
            prefix /= 2;

        }
        reverse(begin(res),end(res));
        return res;
    }
    int minOperations(vector<int>& nums, int k) {
        /*  001
            100



        */

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        

        int prefix = nums[0];
        for(int i=1;i<nums.size();i++){
            prefix ^= nums[i];
        }

        // cout<<"Prefix --> "<<prefix<<endl;
        string preBinary = createBinary(prefix);
        string preK = createBinary(k);

        int count = 0;

        int i=preBinary.size()-1, j = preK.size()-1;
        // cout<<"PREBINARY --> "<<preBinary<<endl;
        // cout<<"PRE_K --> "<<preK<<endl;
        while(i>= 0 && j>=0){
            if(preBinary[i] != preK[j]){
                count++;
            }
            i--;
            j--;
        }

        while(i>=0){
            if(preBinary[i] != '0'){
                count++;
            }
            i--;
        }

        while(j>=0){
            if(preK[j] != '0'){
                count++;
            }
            j--;
        }   

        return count;
    }
};