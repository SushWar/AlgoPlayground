#include <bits/stdc++.h>
using namespace std;

#define pp pair<int,int>
class Solution {
public:
    vector<int> optionOne(vector<int>& nums, int k){
         ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);


        if(k==1) return nums;
        
        priority_queue<pp>order;
        vector<int>res;
        int i = 0, n = nums.size(), j=0;
        for(i;i<k;i++){
            order.push({nums[i],i});
        }

        while(i<n){
            while(!order.empty() && order.top().second < j){order.pop();}
            pp take = order.top();
            order.pop();

            res.push_back(take.first);

            order.push({nums[i], i});

            if(take.second > j){
                order.push(take);
            }

            i++;
            j++;
        }

        while(!order.empty() && order.top().second < j){order.pop();}
        res.push_back(order.top().first);
        return res;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        int greaterRight[n];
        // cout<<"GREATER RIGHT "<<endl;
        greaterRight[0] = nums[0];
        // cout<<greaterRight[0]<<" ";
        for(int i=1;i<n;i++){
            if(i%k == 0){
                greaterRight[i] = nums[i];
            }
            else{
                greaterRight[i] = max(greaterRight[i-1], nums[i]);
            }
            // cout<<greaterRight[i]<<" ";
        }

        // cout<<endl;
        // cout<<"GREATER LEFT "<<endl;
        int greaterLeft[n];
        greaterLeft[n-1] = nums[n-1];
        // cout<<greaterLeft[n-1]<<" ";
       for(int i=n-2;i>=0;i--){
        if(i%k==0){
            greaterLeft[i] = nums[i];
        }
        else{
            greaterLeft[i] = max(greaterLeft[i+1], nums[i]);
        }
        // cout<<greaterLeft[i]<<" ";
       }

       vector<int>ans;
       ans.reserve(n-k+1);

       for(int i=0;i<=n-k;i++){
        ans.emplace_back(max(greaterLeft[i],greaterRight[i+k-1] ));
       }

       return ans;
    }
};