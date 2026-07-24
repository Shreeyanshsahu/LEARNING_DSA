class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (i == 0 || i == m - 1) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                        grid[i][j] = 0;
                    }
                }
            } else {
                if (grid[i][0] == 1) {
                    q.push({i, 0});
                    vis[i][0] = 1;
                    grid[i][0] = 0;
                }

                if (grid[i][n - 1] == 1) {
                    q.push({i, n - 1});
                    vis[i][n - 1] = 1;
                    grid[i][n - 1] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x + 1 < m && vis[x + 1][y] == 0 && grid[x + 1][y] == 1) {
                vis[x + 1][y] = 1;
                q.push({x + 1, y});
                grid[x + 1][y] =0;
            }
            if (x - 1 > -1 && vis[x - 1][y] == 0 && grid[x - 1][y] ==1) {
                vis[x - 1][y] = 1;
                q.push({x - 1, y});
                grid[x - 1][y] =0;
            }
            if (y + 1 < n && vis[x][y + 1] == 0 && grid[x][y + 1] == 1) {
                vis[x][y + 1] = 1;
                q.push({x, y + 1});
                grid[x][y + 1] = 0;
            }
            if (y - 1 > -1 && vis[x][y - 1] == 0 && grid[x][y - 1] == 1) {
                vis[x][y - 1] = 1;
                q.push({x, y - 1});
                grid[x][y - 1] = 0;
            }
        }
        int ans=0;
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};