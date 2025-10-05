#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

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
    /*
    A balanced binary tree means every node in the tree must be balanced, not
    just the root.

    For a node to be balanced, the height difference between its left and right
    subtrees must be ≤ 1.

    This rule must hold for every single node in the tree, recursively down to the
    leaves.

    So even if the root is balanced, if any subtree somewhere is unbalanced, the
    whole tree is considered unbalanced.
    */
    int level(TreeNode* head) {
        if (!head)
            return 0;
        // cout<<head->val<<" ";
        int levels = 1;
        levels = max(level(head->left), level(head->right)) + 1;
        return levels;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        int count = abs(level(root->left) - level(root->right));
        return count <= 1 and isBalanced(root->left) and
               isBalanced(root->right);
    }
};
int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);

    Solution sol;
    if (sol.isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is NOT balanced." << endl;
    }
    return 0;
}
