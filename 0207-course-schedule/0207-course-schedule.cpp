class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& paths, int node) {
        vis[node] = true;
        paths[node] = true;
        for (auto ele : adj[node]) {
            if (vis[ele]&&paths[ele])
                return false;
            if (!vis[ele]) {
                if (!dfs(adj, vis,paths, ele))
                    return false;
            }
        }
        paths[node]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& edges) {
        vector<vector<int>> adj(numCourses);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        vector<bool> vis(adj.size(), false);
        vector<bool> paths(adj.size(), false);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                vis[i]=true;
                paths[i]=true;
                if (!dfs(adj, vis,paths, i))
                    return false;
                paths[i]=false;
            }
        }
        return true;
    }
};