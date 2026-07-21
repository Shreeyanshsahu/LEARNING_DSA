class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> mp;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(mp.count(k-(node->val))){
                return true;
            }
            mp[node->val]=1;
            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }
        return false;
    }
};