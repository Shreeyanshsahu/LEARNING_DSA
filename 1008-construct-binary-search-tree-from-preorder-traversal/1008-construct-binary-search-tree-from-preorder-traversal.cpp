class Solution {
public:

        TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);

        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        if(pre.size()==0) return nullptr;
        TreeNode* root = new TreeNode(pre[0]);
        for(int i = 1;i<pre.size();i++){
            root=insertIntoBST(root,pre[i]);
        }
        return root;
    }
};