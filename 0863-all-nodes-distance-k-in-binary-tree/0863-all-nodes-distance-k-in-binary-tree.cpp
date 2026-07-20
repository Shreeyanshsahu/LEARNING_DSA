class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> mp;
        queue<TreeNode*> q;
        q.push(root);
        mp[root] = {};
        while (!q.empty()) {
            int n = q.size();
            while (n > 0) {
                TreeNode* orgin = q.front();
                q.pop();
                if (orgin->left) {
                    mp[orgin->left].push_back(orgin);
                    mp[orgin].push_back(orgin->left);
                    q.push(orgin->left);
                }
                if (orgin->right) {
                    mp[orgin->right].push_back(orgin);
                    mp[orgin].push_back(orgin->right);
                    q.push(orgin->right);
                }
                n--;
            }
        }
        vector<int> ans;
        unordered_map<TreeNode*, int> vis;
        int n = 0;
        q.push(target);
        vis[target]=1;
        while (n < k) {
            vector<TreeNode*> temp;
            while (!q.empty()) {
                for (auto nodes : mp[q.front()]) {
                    if (vis.count(nodes) == 0) {
                        temp.push_back(nodes);
                        vis[nodes] = 1;
                    }
                }
                q.pop();
            }
            for (auto travelednodes : temp) {
                q.push(travelednodes);
            }
            n++;
        }
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};