#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    void helper(TreeNode* root, string s, vector<string>& ans) {
        if (!root) return;

        if (s == "") s += to_string(root->val);
        else {
            s += "->";
            s += to_string(root->val);
        }

        if (!root->left && !root->right) { 
            ans.push_back(s);
            return;
        }

        helper(root->left, s, ans);
        helper(root->right, s, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};

int main() {
    /*
        Tree:
              1
             / \
            2   3
             \
              5

        Expected paths:
        ["1->2->5", "1->3"]
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<string> paths = sol.binaryTreePaths(root);

    cout << "Binary Tree Paths: " << endl;
    for (auto& path : paths) {
        cout << path << endl;
    }

    return 0;
}
