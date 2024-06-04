/*\

Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {

        /*
            a = 3
            b = 5
            c = 7

            247
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


       unordered_map<char,int>arr;

       for(int i=0;i<s.size();i++){
        arr[s[i]]++;
       }

    //    int result = 0;
    //     for(auto x:arr){
    //         result += x.second/2*2;
    //         if(result % 2 ==0 && x.second % 2 == 1){
    //             result++;
    //         }
    //     }
    //     return result;

        priority_queue<int> order;
       for(auto x: arr){
            if(x.second > 0){
                order.push(x.second);
            }
       }

        int count = 0;
        bool flag = true;

        while(!order.empty()){
            int take = order.top();
            order.pop();

            if(take % 2 != 0){
                if(flag){
                    count += take;
                    flag = false;
                }
                else if(!flag && take > 1){
                    count += (take-1);
                }
            }
            else{
                count += take;
            }
        }

        return count;

    }
};