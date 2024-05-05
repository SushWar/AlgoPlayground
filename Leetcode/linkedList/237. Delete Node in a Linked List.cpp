#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list. */
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        // cout<<node->val<<endl;
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        ListNode *prev;

        while(node->next != NULL){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }

        prev->next = NULL;
        
    }
};