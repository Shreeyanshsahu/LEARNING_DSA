#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
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
    void helper(TreeNode* root, int current, int target, int &count) {
        if (!root) return;

        current += root->val;

        // Leaf node
        if (!root->left && !root->right) {
            if (current == target) count++;
            return;
        }

        // Recurse on children
        helper(root->left, current, target, count);
        helper(root->right, current, target, count);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int count = 0;
        helper(root, 0, targetSum, count);
        return count > 0;
    }
};

// Example usage
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution s;
    cout << boolalpha << s.hasPathSum(root, 22) << endl; // Output: true

    return 0;
}
