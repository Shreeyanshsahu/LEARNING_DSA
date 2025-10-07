#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Solution class with all traversals
class Solution {
public:
    // Preorder Traversal (Root -> Left -> Right)
    void preorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }

    // Inorder Traversal (Left -> Root -> Right)
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    // Postorder Traversal (Left -> Right -> Root)
    void postorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};

int main() {
    // Create a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution sol;
    vector<int> pre, in, post;

    sol.preorder(root, pre);
    sol.inorder(root, in);
    sol.postorder(root, post);

    // Print results
    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << "\n";

    cout << "Inorder: ";
    for (int x : in) cout << x << " ";
    cout << "\n";

    cout << "Postorder: ";
    for (int x : post) cout << x << " ";
    cout << "\n";

    return 0;
}
