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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if ((!p && q) || (!q && p) || (p->val != q->val)) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Testing the code
int main() {
    /*
        Tree 1:         Tree 2:
            1               1
           / \             / \
          2   3           2   3
    */
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(3);

    Solution sol;
    if (sol.isSameTree(t1, t2))
        cout << "Both trees are the same" << endl;
    else
        cout << "Trees are different" << endl;

    return 0;
}
