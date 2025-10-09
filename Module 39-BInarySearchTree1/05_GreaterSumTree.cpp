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
    int count = 0;

    TreeNode* bstToGst(TreeNode* root) {
        if (!root) return nullptr;
        bstToGst(root->right);
        count += root->val;
        root->val = count;
        bstToGst(root->left);
        return root;
    }
};

// Helper function: inorder print
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    Solution sol;
    sol.bstToGst(root);

    cout << "Inorder of Greater Sum Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
