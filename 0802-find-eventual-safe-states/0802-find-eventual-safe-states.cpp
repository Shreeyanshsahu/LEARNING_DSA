class Solution {
public:
     bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& paths, vector<bool>& check, int node) {
        vis[node] = true;
        paths[node] = true;
        for (auto ele : adj[node]) {
            if (vis[ele]&&paths[ele])
                return false;
            if (!vis[ele]) {
                if (!dfs(adj, vis,paths,check, ele))
                    return false;
            }
        }
        check[node]=true;
        paths[node]=false;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> vis(graph.size(), false);
        vector<bool> paths(graph.size(), false);
        vector<bool> check(graph.size(), false);
        vector<int> ans;
        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i]) {
                dfs(graph, vis, paths, check, i);
            }
        }
        for(int i =0;i<check.size();i++){
            if(check[i])ans.push_back(i);
        }
        return ans;
    }
};