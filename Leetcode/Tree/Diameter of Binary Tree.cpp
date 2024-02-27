#include <bits/stdc++.h>
using namespace std;



 /* Definition for a binary tree node. 
    (https://leetcode.com/problems/diameter-of-binary-tree/?envType=daily-question&envId=2024-02-27)
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
    int result;
public:
    int travel(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        
       int left = travel(root->left);
       int right = travel(root->right);

       result = max(result,(left+right));

       return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        result = 0;

        int check = travel(root);

        cout<<check<<endl;
        return result;

        
        
    }
};