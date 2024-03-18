#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() : Node(0) {}

    Node(int _val) {
        val = _val;
        children = vector<Node*>();
    }

    static string serialize(Node* root) {
        if (root == nullptr)
            return "[]";
        string res = "[" + to_string(root->val) + ",null,";
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int count = q.size();
            while (count-- > 0) {
                Node* curr = q.front();
                q.pop();
                for (Node* child : curr->children) {
                    q.push(child);
                    res += to_string(child->val) + ",";
                }
                res += "null,";
            }
        }
        res[res.length() - 1] = ']';
        return res;
    }

    static Node* deserialize(string input) {
        if (input == "[]")
            return nullptr;

        input = input.substr(1, input.length() - 2);
        vector<string> nodes;
        stringstream ss(input);
        string item;
        while (getline(ss, item, ',')) {
            nodes.push_back(item);
        }

        Node* root = new Node(stoi(nodes[0]));
        queue<Node*> q;
        q.push(root);

        int index = 2;
        while (!q.empty()) {
            Node* par = q.front();
            q.pop();
            while (index < nodes.size()) {
                string str = nodes[index++];
                if (str == "null")
                    break;

                Node* child = new Node(stoi(str));
                par->children.push_back(child);
                q.push(child);
            }
        }

        return root;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;
        if (root->children.empty())
            return 1;

        vector<int> heights;
        for (Node* item : root->children) {
            heights.push_back(maxDepth(item));
        }

        return *max_element(heights.begin(), heights.end()) + 1;
    }
};

int main() {
    string input;
    Solution ob;
    while (getline(cin, input)) {
        Node* root = Node::deserialize(input);
        cout << ob.maxDepth(root) << endl;
    }
    return 0;
}