class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        long long width = 1;
        while (!q.empty()) {
            long long st = q.front().second;
            long long n = q.size();
            long long end = st;
            while (n > 0) {
                auto [node, idx] = q.front();
                idx -= st; // Normalize
                end = idx;
                if (node->left)
                    q.push({node->left, idx * 2});
                if (node->right)
                    q.push({node->right, idx * 2 + 1});
                q.pop();
                n--;
            }
            width = max(width, end+1);
        }
        return width;
    }
};