class Solution {
public:
    bool check(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i <= m - 1 && j <= n - 1;
    }
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0) return 0;

        priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
            > q;

        q.push({0,{0,0}});
        vector<vector<int>> heightdiff(m, vector<int>(n, INT_MAX));
        heightdiff[0][0] = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while (!q.empty()) {
            auto [diff, cord] = q.top();
            auto [x, y] = cord;
            q.pop();
            if (diff != heightdiff[x][y]) continue; // stale entry

            if (x == m-1 && y == n-1) return diff;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (check(nx, ny, m, n)) {
                    int newdiff = max(diff, abs(grid[nx][ny] - grid[x][y]));
                    if (newdiff < heightdiff[nx][ny]) {
                        heightdiff[nx][ny] = newdiff;
                        q.push({newdiff, {nx, ny}});
                    }
                }
            }
        }
        return heightdiff[m-1][n-1] == INT_MAX ? -1 : heightdiff[m-1][n-1];
    }
};