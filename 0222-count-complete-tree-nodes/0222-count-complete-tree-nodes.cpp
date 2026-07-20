class Solution {
public:
    int rightheight(TreeNode*root){
        int height=0;
        while(root){
            height++;
            root=root->right;
        }
        return height;
    }
    int leftheight(TreeNode*root){
        int height=0;
        while(root){
            height++;
            root=root->left;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int left = leftheight(root);
        int right = rightheight(root);
        if(left==right) return (1<<left) -1;
        //1<<x 2powx
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};