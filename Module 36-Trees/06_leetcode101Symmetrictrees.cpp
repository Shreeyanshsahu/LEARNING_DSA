#include <iostream>
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
    bool same(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && same(p->left, q->right) && same(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return same(root->left, root->right);
    }
};

// Helper function (in-order traversal to check tree structure)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
        Symmetric Tree Example:
                 1
               /   \
              2     2
             / \   / \
            3   4 4   3

        Asymmetric Example:
                 1
               /   \
              2     2
               \     \
                3     3
    */

    // Symmetric tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(3);
    root1->left->right = new TreeNode(4);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(3);

    // Asymmetric tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->right = new TreeNode(3);
    root2->right->right = new TreeNode(3);

    Solution sol;
    cout << "Tree 1 symmetric? " << (sol.isSymmetric(root1) ? "Yes" : "No") << endl;
    cout << "Tree 2 symmetric? " << (sol.isSymmetric(root2) ? "Yes" : "No") << endl;

    return 0;
}
