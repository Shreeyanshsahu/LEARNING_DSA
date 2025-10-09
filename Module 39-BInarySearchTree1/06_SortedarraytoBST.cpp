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
    TreeNode* Tree(vector<int>& nums, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = (lo + hi) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = Tree(nums, lo, mid - 1);
        root->right = Tree(nums, mid + 1, hi);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        return Tree(nums, 0, nums.size() - 1);
    }
};

// Helper: inorder traversal to verify the BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};

    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
