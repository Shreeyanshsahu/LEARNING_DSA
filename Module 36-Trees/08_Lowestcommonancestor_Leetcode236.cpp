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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }
};

int main() {
    /*
            Example tree:
                  3
                 / \
                5   1
               / \ / \
              6  2 0  8
                / \
               7   4

        LCA(5,1) = 3
        LCA(5,4) = 5
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* lca1 = sol.lowestCommonAncestor(root, root->left, root->right);       // 5 & 1
    TreeNode* lca2 = sol.lowestCommonAncestor(root, root->left, root->left->right->right); // 5 & 4

    cout << "LCA of 5 and 1: " << lca1->val << endl;
    cout << "LCA of 5 and 4: " << lca2->val << endl;

    return 0;
}
