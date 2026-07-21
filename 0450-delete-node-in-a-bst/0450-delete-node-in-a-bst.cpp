class Solution {
public:
    TreeNode* pred(TreeNode* root) {
        if(!root) return nullptr;
        root=root->left;
        while(root->right!=nullptr){
            root=root->right;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key) {
            if (!root->left and !root->right) { //case 1: a leaf node
                delete root;
                return nullptr;
            } else if (!root->left or !root->right) { // case2: with one child
                if(root->left==nullptr){
                    TreeNode* curr=root->right;
                    delete root;
                    return curr;
                }
                else{
                    TreeNode* curr=root->left;
                    delete root;
                    return curr;
                }
            }
            else{
                TreeNode* temp=pred(root);
                root->val=temp->val;
                root->left=deleteNode(root->left,root->val);
                return root;
            }
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};