class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& paths, vector<int>& ans, int node) {
        vis[node] = true;
        paths[node] = true;
        for (auto ele : adj[node]) {
            if (vis[ele]&&paths[ele])
                return false;
            if (!vis[ele]) {
                if (!dfs(adj, vis,paths,ans, ele))
                    return false;
            }
        }
        ans.push_back(node);
        paths[node]=false;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto edge :prerequisites ) {
            adj[edge[0]].push_back(edge[1]);//ordering is change because we need to b from [a,b] to finish a thats why 
        }
        vector<bool> vis(adj.size(), false);
        vector<bool> paths(adj.size(), false);
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!dfs(adj, vis,paths,ans, i))
                    return {};
            }
        }
        return ans;
    }
};