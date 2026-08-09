class Solution {
public:
    bool check(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i <= m - 1 && j <= n - 1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || grid[0][0] != 0 || grid[m-1][n-1] != 0) return -1;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0}, 1});
        visited[0][0] = true;

        int dx[] = {1,1,0,0,-1,-1,1,-1};
        int dy[] = {0,1,1,-1,0,-1,-1,1};

        while (!q.empty()) {
            auto [cord, dist] = q.front();
            auto [x, y] = cord;
            q.pop();

            if (x == m-1 && y == n-1) return dist;

            for (int k = 0; k < 8; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (check(nx, ny, m, n) && !grid[nx][ny] && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }
        return -1;
    }
};