#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        
        /*
            1432219

            1,0 | 1,5 | 2,3 | 2,4 | 3,2 | 4,1 | 9,6

            1,0 | 4,1 | 3,2 | 2,3 | 2,4 | 1,5 | 9,6

            -> 1
            -> 4,1
            -> 3,1 >> k-1
            -> 2,1 >> k-1
            -> 2,1 >> k-1
            -> 

        */
        if(num.size() <= k) return "0";
        if(k==0) return num;

        stack<char>order;
        order.push(num[0]);

        for(int i=1;i<num.size();i++){
           while(k>0 && !order.empty() && order.top() > num[i]){
            order.pop();
            k--;
           }
           order.push(num[i]);

           if(order.size()==1 && num[i] == '0') order.pop();
        }

        string res = "";
        while(!order.empty() && k){
            
            order.pop();
            k--;
        }

        while(!order.empty()) {
            res += order.top();
            order.pop();
        }
        if(res.size()==0) return "0";
        reverse(begin(res),end(res));


        return res;
        
    }
};