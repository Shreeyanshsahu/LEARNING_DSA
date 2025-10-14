#include <iostream>
#include <queue>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left != NULL) {
                // Find the rightmost node of the left subtree
                TreeNode* pred = curr->left;
                while (pred->right != NULL) {
                    pred = pred->right;
                }
                // Rewire connections
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            // Move to the next node
            curr = curr->right;
        }
    }
};

// Helper: build sample tree
TreeNode* buildSampleTree() {
    // Example Tree:
    //      1
    //     / \
    //    2   5
    //   / \   \
    //  3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    return root;
}

// Helper: print flattened linked list
void printFlattened(TreeNode* root) {
    cout << "Flattened Linked List: ";
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();

    cout << "Before flattening:" << endl;
    cout << "Tree (Level Order): ";
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == NULL) {
            cout << "null ";
            continue;
        }
        cout << node->val << " ";
        q.push(node->left);
        q.push(node->right);
    }
    cout << endl;

    sol.flatten(root);

    cout << "\nAfter flattening:" << endl;
    printFlattened(root);

    return 0;
}
