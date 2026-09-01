class Solution {
    bool check(int x, int y, int m, int n,vector<vector<int>>& grid) {
        return x < m && y < n && x >= 0 && y >= 0&&!grid[x][y];
    }

    int helper(int x, int y, int m, int n, vector<vector<int>>& dp,vector<vector<int>>& grid) {
        if (x == 0 && y == 0)
            return 1;
        if (!check(x, y, m, n,grid))
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        int top = 0;
        int left = 0;
        if (check(x - 1, y, m, n,grid)) {
            top = helper(x - 1, y, m, n, dp,grid);
        }
        if (check(x, y - 1, m, n,grid)) {
            left = helper(x, y - 1, m, n, dp,grid);
        }
        return dp[x][y] = top + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,m,n,dp,grid);
    }
};