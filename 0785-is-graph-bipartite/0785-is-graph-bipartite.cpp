class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        queue<pair<int, int>> q;
        vector<int> color(adj.size(), -1);
        for (int i = 0; i < adj.size(); i++) {
            if (color[i] == -1) {
                q.push({i, 0});
                color[i] = 0;
                while (!q.empty()) {
                    auto [node, col] = q.front();
                    for (auto nodes : adj[node]) {
                        if (color[nodes] == -1) {
                            if (col) {
                                q.push({nodes, 0});
                                color[nodes] = 0;
                            } else {
                                q.push({nodes, 1});
                                color[nodes] = 1;
                            }
                        } else if (color[nodes] == 0 && color[nodes] == col) {
                            return false;
                        } else if (color[nodes] == 1 && color[nodes] == col) {
                            return false;
                        }
                    }
                    q.pop();
                }
            }
        }
        return true;
    }
};