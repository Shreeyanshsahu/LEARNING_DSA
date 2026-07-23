class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc,
                                  int color) {
        if (grid[sr][sc] == color)
            return grid;
        int target = grid[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int m = grid.size();
        int n = grid[0].size();
        grid[sr][sc] = color;
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                size--;
                auto [x, y] = q.front();
                q.pop();
                // right
                if (x + 1 < m && y < n && grid[x + 1][y] == target) {
                    q.push({x + 1, y});
                    grid[x + 1][y] = color;
                }
                // left
                if (x - 1 >= 0 && y < n && grid[x - 1][y] == target) {
                    q.push({x - 1, y});
                    grid[x - 1][y] = color;
                }
                // up
                if (x < m && y + 1 < n && grid[x][y + 1] == target) {
                    q.push({x, y + 1});
                    grid[x][y + 1] = color;
                }
                // down
                if (x < m && y - 1 >= 0 && grid[x][y - 1] == target) {
                    q.push({x, y - 1});
                    grid[x][y - 1] = color;
                }
            }
        }
        return grid;
    }
};