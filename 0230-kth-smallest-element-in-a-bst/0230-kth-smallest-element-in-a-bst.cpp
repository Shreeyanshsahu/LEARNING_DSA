class Solution {
public:
    int ans = -1;
    void inorder(TreeNode* root,int k,int &x) {
        if (root == nullptr)
            return;
        inorder(root->left,k,x);
        x++;
        if(x==k){
            ans=root->val;
            return;
        }
        inorder(root->right,k,x);
    }
    int kthSmallest(TreeNode* root, int k) {
        int x =0;
        inorder(root,k,x);
        return ans;
    }
};