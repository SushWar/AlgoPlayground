#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        stack<pair<int,char>>order;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                order.push({i,'('});
            }
            else if(s[i]==')'){
                if(!order.empty() && order.top().second == '('){
                    order.pop();
                }
                else{
                    order.push({i,')'});
                }
            }
        }
        
        string res = "";
        for(int i=n-1;i>=0;i--){

            int idx = !order.empty() ? order.top().first : -1;

            if(i==idx){
                order.pop();
            }
            else{
                res += s[i];
            }
        }

        reverse(begin(res),end(res));
        return res;
        
    }
};