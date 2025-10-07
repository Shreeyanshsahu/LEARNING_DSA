#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    TreeNode* Tree(vector<int>& preorder, vector<int>& inorder, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return nullptr;

        TreeNode* root = new TreeNode(preorder[s1]);
        int rootnode = preorder[s1];

        int k = s2;
        for (int i = s2; i <= e2; i++) {
            if (inorder[i] == rootnode) {
                k = i;
                break;
            }
        }

        int remaining = k - s2;
        root->left = Tree(preorder, inorder, s1 + 1, s1 + remaining, s2, k - 1);
        root->right = Tree(preorder, inorder, s1 + remaining + 1, e1, k + 1, e2);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Tree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

// Helper to verify by inorder traversal
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << endl;
    return 0;
}
