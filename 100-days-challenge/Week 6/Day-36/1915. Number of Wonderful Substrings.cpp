#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        /*
            

            a a a b 
        */


        unordered_map<ll,ll>order;
        order[0]=1;
        ll prefix=0, ans=0;

        for(char c: word){
            prefix = prefix ^ (1<<(c-'a'));
            ans += order[prefix];
            for(char l='a';l<='j';l++){
                ll oddpatern = prefix ^ (1<<(l-'a'));
                ans += order[oddpatern];
            }
            order[prefix]++;
        }

        return ans;
    }
};