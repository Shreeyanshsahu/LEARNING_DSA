class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr) {
            TreeNode* leftsub = curr->left;
            TreeNode* rightsub = curr->right;
            if (curr->left) {
                curr->left = nullptr;
                curr->right = nullptr;
                flatten(leftsub);
                curr->right = leftsub;
                while(leftsub->right){
                    leftsub=leftsub->right;
                }
                leftsub->right = rightsub;
                curr = rightsub;
            } else {
                curr = curr->right;
            }
        }
    }
};