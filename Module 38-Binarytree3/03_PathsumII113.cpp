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
    void helper(TreeNode* root, vector<int>& temp, vector<vector<int>>& ans, int current, int target) {
        if (!root) return;

        current += root->val;
        temp.push_back(root->val);

        // If it's a leaf node and path sum equals target
        if (!root->left && !root->right && current == target)
            ans.push_back(temp);

        // Recurse left and right
        helper(root->left, temp, ans, current, target);
        helper(root->right, temp, ans, current, target);

        // Backtrack
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(root, temp, ans, 0, targetSum);
        return ans;
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
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution s;
    vector<vector<int>> res = s.pathSum(root, 22);

    cout << "Paths with sum 22:\n";
    for (auto& path : res) {
        for (int val : path)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
