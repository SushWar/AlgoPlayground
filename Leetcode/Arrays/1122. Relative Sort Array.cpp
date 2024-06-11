/*
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not 
appear in arr2 should be placed at the end of arr1 in ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        int n1 = arr1.size(), n2 = arr2.size();
        int temp[1001];

        fill(temp, end(temp), n2);

        for(int i=0;i<n2;i++){
            temp[arr2[i]]=i;
        }

        sort(arr1.begin(), arr1.end(), [&](int x, int y){
            if(temp[x] == temp[y]) return x<y;
            return temp[x] < temp[y];
        });

        return arr1;
        
        // map<int,int>order;

        // for(int x: arr2){
        //     order[x] = 0;
        // }


        // for(int x: arr1){
        //     order[x]++;
        // }

        
        // vector<int>result;

        // for(int x: arr2){
        //     while(order[x] > 0){
        //         result.emplace_back(x);
        //         order[x]--;
        //     }
        //     order.erase(x);
        // }

        // for(auto x: order){
        //     int temp = x.second;
        //     int val = x.first;

        //     while(temp--){
        //         result.emplace_back(val);
        //     }
        // }

        // return result;
    }
};