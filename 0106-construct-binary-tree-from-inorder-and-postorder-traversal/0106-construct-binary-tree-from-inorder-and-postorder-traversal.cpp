class Solution {
public:
    TreeNode* build(vector<int>& post, vector<int>& in,
                    int postst, int postend,
                    int inst, int inend) {

        if (postst > postend || inst > inend ||
            postst >= post.size() || inst >= in.size() ||
            postend < 0 || inend < 0)
            return nullptr;

        if (postst == postend || inst == inend) {
            return new TreeNode(post[postend]);
        }

        TreeNode* root = new TreeNode(post[postend]);

        int pivot = 0;
        for (int i = inst; i <= inend; i++) {
            if (post[postend] == in[i]) {
                pivot = i;
                break;
            }
        }

        int leftSize = pivot - inst;

        root->left = build(post, in,
                           postst,
                           postst + leftSize - 1,
                           inst,
                           pivot - 1);

        root->right = build(post, in,
                            postst + leftSize,
                            postend - 1,
                            pivot + 1,
                            inend);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder, inorder,
                     0, postorder.size() - 1,
                     0, inorder.size() - 1);
    }
};