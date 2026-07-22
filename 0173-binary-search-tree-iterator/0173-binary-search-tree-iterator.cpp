class BSTIterator {
public:
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
        TreeNode* curr=root;

        s.push(curr);
        pushele(curr);
    }
    
    void pushele(TreeNode*curr){
        while(curr->left){
            s.push(curr->left);
            curr=curr->left;
        }
    }
    int next() {
        TreeNode* temp=s.top();
        s.pop();
        int val=temp->val;
        if(temp->right){
            temp=temp->right;
            s.push(temp);
            pushele(temp);
        }
        return val;
    }
    
    bool hasNext() {
        return !s.empty();
            }
};
