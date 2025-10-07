#include <iostream>
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
    int helper(TreeNode* root, long long current, int target) {
        if (!root) return 0;

        current += root->val;
        int count = (current == target);

        count += helper(root->left, current, target);
        count += helper(root->right, current, target);

        return count;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        int ans = helper(root, 0, targetSum);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);

        return ans;
    }
};

// Example usage
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(-3);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(11);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(-2);
    root->left->right->right = new TreeNode(1);

    Solution s;
    int target = 8;
    cout << "Number of paths with sum " << target << ": "
         << s.pathSum(root, target) << endl;

    return 0;
}
