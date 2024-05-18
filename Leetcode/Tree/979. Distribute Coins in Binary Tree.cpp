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
    int result;
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        result += abs(left) + abs(right);

        return left + right + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        
        /*
            1. excalty 1 coin at every node
            2. total coins == nodes
            3. 
        */
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        

        result = 0;

        dfs(root);

        return result;


    }
};