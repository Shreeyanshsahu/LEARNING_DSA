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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root || root->val == val)
            return root;
        if (root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int val = 2;
    TreeNode* result = sol.searchBST(root, val);

    if (result)
        cout << "Found node with value: " << result->val << endl;
    else
        cout << "Value not found in BST" << endl;

    return 0;
}
