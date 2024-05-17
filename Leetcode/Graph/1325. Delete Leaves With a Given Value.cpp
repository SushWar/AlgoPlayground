#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, 
it should also be deleted (you need to continue doing that until you cannot).
 */

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        
        if(root->left){
            root->left = removeLeafNodes(root->left, target);
        }

        if(root->right){
            root->right = removeLeafNodes(root->right, target);
        }

        if(root->left == NULL && root->right == NULL && root->val == target){
            root = NULL;
        }

        return root;


    }
};