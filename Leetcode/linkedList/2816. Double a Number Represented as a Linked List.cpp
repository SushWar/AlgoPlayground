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
    int carry;
public:
    ListNode* backTrack(ListNode* head){
        
        if(head == NULL){
            return NULL; 
        }

        ListNode* result = backTrack(head->next);

        int data = (2 * head->val) + carry;
        int rem = data;
        if(data > 9){
            rem = data%10;
            carry = data/10;
        }
        else{
            carry = 0;
        }

        ListNode* newNode = new ListNode(rem);
        newNode->next = result;

        return newNode;
    }
    ListNode* doubleIt(ListNode* head) {
        /*
        
            go to last node start the multiplication 2 and take carry 
        */

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        

        carry = 0;

        ListNode* result = backTrack(head);

        if(carry > 0){
            ListNode* temp = new ListNode(carry);
            temp->next = result;
            result = temp;
        }

        return result;
        
    }
};