#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

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
};

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;
    TreeNode* root = nullptr;

    // Insert values
    root = sol.insertIntoBST(root, 4);
    root = sol.insertIntoBST(root, 2);
    root = sol.insertIntoBST(root, 7);
    root = sol.insertIntoBST(root, 1);
    root = sol.insertIntoBST(root, 3);
    root = sol.insertIntoBST(root, 5);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}