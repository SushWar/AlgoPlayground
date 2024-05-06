#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list. */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

    ListNode* queueMethod(ListNode* head){
         deque<int>order;

        ListNode* temp = head;

        while(temp){
            int data = temp->val;
            if(order.empty()){
                order.push_back(data);
            }
            else{
                while(!order.empty() && order.back()<data){
                    order.pop_back();
                }

                order.push_back(data);
            }
            temp = temp->next;
        }

        ListNode* result = new ListNode();
        ListNode* travel = result;

        while(!order.empty()){
            int data = order.front();
            order.pop_front();
            ListNode* create = new ListNode(data);
            travel->next = create;
            travel = travel->next;
        }

        return result->next;
    }
    ListNode* removeNodes(ListNode* head) {

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(head == NULL) return head;
        head->next = removeNodes(head->next);
        if(head->next == NULL) return head;

        if(head->next->val > head->val){return head->next;}
        return head;
        
       
    }
};