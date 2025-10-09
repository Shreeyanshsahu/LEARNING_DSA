#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void validate(TreeNode* root, vector<int>& ans) {
        if (!root) return;
        validate(root->left, ans);
        ans.push_back(root->val);
        validate(root->right, ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        validate(root, ans);
        for (int i = 1; i < ans.size(); i++) {
            if (ans[i] <= ans[i - 1]) return false;
        }
        return true;
    }
};

int main() {
    // Example tree
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution sol;
    cout << (sol.isValidBST(root) ? "Valid BST" : "Invalid BST") << endl;
    return 0;
}
