#include <bits/stdc++.h>
using namespace std;


 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution {
public:
    int sumNumbers(TreeNode* root) {
        
        queue<pair<TreeNode*,int>>order;

        int result = 0;
        order.push({root, root->val});

        while(!order.empty()){
            int n = order.size();

            for(int i=0;i<n;i++){
                auto took = order.front();
                
                order.pop();

                if(took.first->left == NULL && took.first->right == NULL){
                    result += took.second;
                }

                if(took.first->left != NULL){
                    int insert = took.second*10 +  took.first->left->val;
                    order.push({took.first->left,insert});
                }

                if(took.first->right != NULL){
                     int insert = took.second*10 +  took.first->right->val;
                    order.push({took.first->right,insert});
                }
            }
        }

        return result;
    }
};