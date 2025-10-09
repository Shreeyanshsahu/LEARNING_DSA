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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& pre) {
        if (pre.empty()) return nullptr;
        TreeNode* root = new TreeNode(pre[0]);
        for (int i = 1; i < pre.size(); i++) {
            root = insertIntoBST(root, pre[i]);
        }
        return root;
    }
};

// Helper function: inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
