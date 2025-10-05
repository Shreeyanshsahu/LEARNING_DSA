#include <iostream>
#include <algorithm>
#include <climits>
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
    int maxdia = INT_MIN;

    int level(TreeNode* head) {
        if (!head) return 0;
        return max(level(head->left), level(head->right)) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int currmax = level(root->left) + level(root->right);
        maxdia = max(currmax, maxdia);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);

        return maxdia;
    }
};

// Testing the code
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of tree: " << sol.diameterOfBinaryTree(root) << endl;

    return 0;
}
