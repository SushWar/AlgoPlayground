#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    static TreeNode* stringToTreeNode(string input) {
        input = input.substr(1, input.length() - 2);
        if (input.empty()) {
            return nullptr;
        }

        vector<string> parts;
        istringstream iss(input);
        string part;
        while (getline(iss, part, ',')) {
            parts.push_back(part);
        }

        TreeNode* root = new TreeNode(stoi(parts[0]));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        int index = 1;
        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (index < parts.size()) {
                string leftVal = parts[index++];
                if (leftVal != "null") {
                    node->left = new TreeNode(stoi(leftVal));
                    nodeQueue.push(node->left);
                }
            }

            if (index < parts.size()) {
                string rightVal = parts[index++];
                if (rightVal != "null") {
                    node->right = new TreeNode(stoi(rightVal));
                    nodeQueue.push(node->right);
                }
            }
        }
        return root;
    }

    static string treeNodeToString(TreeNode* root) {
        if (root == nullptr) {
            return "[]";
        }

        string output = "";
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()) {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (node == nullptr) {
                output += "null, ";
                continue;
            }

            output += to_string(node->val) + ", ";
            nodeQueue.push(node->left);
            nodeQueue.push(node->right);
        }
        return "[" + output.substr(0, output.length() - 2) + "]";
    }
};

class Solution {
public:
    void duplicateLeft(TreeNode* node) {
        if (node == nullptr) return;

        duplicateLeft(node->left);
        duplicateLeft(node->right);

        TreeNode* copyNode = new TreeNode(node->val);
        copyNode->left = node->left;
        node->left = copyNode;
    }
};

int main() {
    string input;
    getline(cin, input);
    TreeNode* root = TreeNode::stringToTreeNode(input);

    Solution ob;
    ob.duplicateLeft(root);

    cout << TreeNode::treeNodeToString(root) << endl;

    return 0;
}