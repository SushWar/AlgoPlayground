#include <bits/stdc++.h>
using namespace std;


/**
 * Definition for singly-linked list.*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        
        priority_queue<int,vector<int>,greater<int>>order;
        ListNode *take = new ListNode();
        ListNode* temp = take;
        for(int i=0;i<lists.size();i++){
            while(lists[i]){
                order.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        while(!order.empty()){
            ListNode *newNode = new ListNode(order.top());
            order.pop();
            temp->next = newNode;
            temp = temp->next;
        }

        return take->next;
    }
};