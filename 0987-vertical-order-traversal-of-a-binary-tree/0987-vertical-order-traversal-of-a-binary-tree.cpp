
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,pair<int,int>>>q; //Node,<vertical,level
        map<int,map<int,multiset<int>>>nodes;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node= p.first;
            int xaxix = p.second.first;
            int yaxix = p.second.second;
            nodes[xaxix][yaxix].insert(node->val);
            if(node->left){
                q.push({node->left,{xaxix-1,yaxix+1}});
            }
            if(node->right){
                q.push({node->right,{xaxix+1,yaxix+1}});
            }
        }
        vector<vector<int>>ans;
        for (auto p : nodes) {
            vector<int> col;

            for (auto q : p.second) {       // iterate over levels
                for (auto val : q.second) { // iterate over multiset
                    col.push_back(val);
                }
            }

            ans.push_back(col);
        }
        return ans;
    }
};