#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Find inorder predecessor (max in left subtree)
    TreeNode* pred(TreeNode* root) {
        if (!root) return nullptr;
        root = root->left;
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    // Delete a node from BST
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;

        if (root->val == key) {
            // Case 1: Leaf node
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            else if (!root->left || !root->right) {
                TreeNode* child = root->left ? root->left : root->right;
                delete root;
                return child;
            }

            // Case 3: Two children
            else {
                TreeNode* temp = pred(root);
                root->val = temp->val;
                root->left = deleteNode(root->left, temp->val);
            }
        } 
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};

// Helper: Insert into BST (for testing)
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

// Helper: Inorder traversal
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    Solution sol;

    // Build BST: [50, 30, 70, 20, 40, 60, 80]
    TreeNode* root = nullptr;
    vector<int> vals = {50, 30, 70, 20, 40, 60, 80};
    for (int v : vals)
        root = insertBST(root, v);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    // Delete node with key 30
    root = sol.deleteNode(root, 30);

    cout << "Inorder after deleting 30: ";
    inorder(root);
    cout << endl;

    return 0;
}
