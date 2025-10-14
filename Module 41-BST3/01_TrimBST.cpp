#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Your Solution class here

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return nullptr;

        // If current node is smaller than 'low',
        // then the trimmed tree must be in the right subtree.
        if (root->val < low)
            return trimBST(root->right, low, high);

        // If current node is larger than 'high',
        // then the trimmed tree must be in the left subtree.
        if (root->val > high)
            return trimBST(root->left, low, high);

        // Otherwise, the node is within range, 
        // so trim its left and right children recursively.
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    inorder(root);  // Output: 1 2 3
    cout<<endl;
    Solution s;
    TreeNode* trimmed = s.trimBST(root, 1, 3);

    inorder(trimmed);  // Output: 1 2 3
}
