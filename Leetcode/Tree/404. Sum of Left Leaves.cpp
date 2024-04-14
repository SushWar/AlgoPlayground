#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSumTree(TreeNode* home, int incoming){
        
        if(home == NULL){
            return 0;
        }

        int res = 0;
        if(incoming == 1){
           if(home->left == NULL && home->right == NULL){
                return home->val;
           }

            res += findSumTree(home->left, 1) + findSumTree(home->right, -1);
        }
        else{
            res += findSumTree(home->left, 1) + findSumTree(home->right, -1);
        }

        
        return res;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        

        /*
            1 -> left
            -1 -> right
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        
        int res = 0;
        if(root->left != NULL) res += findSumTree(root->left ,1);
        if(root->right != NULL) res += findSumTree(root->right, -1);

        return res;
    }
};