class Solution {
public:
    TreeNode* build(vector<int>& pre, vector<int>& in, int prest, int preend,
                    int inst, int inend) {
        if (prest > preend || inst > inend || prest >= pre.size() ||
            inst >= in.size() || inend < 0 || preend < 0)
            return nullptr;
        if (prest == preend || inst == inend) {
            TreeNode* x = new TreeNode(pre[prest]);
            return x;
        } else {
            TreeNode* x = new TreeNode(pre[prest]);
            int pivot = 0;
            for (int i = inst; i <= inend; i++) {
                if (pre[prest] == in[i]) {
                    pivot = i;
                    break;
                }
            }
            int leftSize = pivot - inst;
            x->left =
                build(pre, in, prest + 1, prest + leftSize, inst, pivot - 1);

            x->right =
                build(pre, in, prest + leftSize + 1, preend, pivot + 1, inend);
            return x;
        }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size() - 1, 0,
                     inorder.size() - 1);
    }
};