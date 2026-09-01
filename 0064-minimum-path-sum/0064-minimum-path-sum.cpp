class Solution {
    bool check(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }
    int helper(int x, int y, int m, int n, vector<vector<int>>& dp,
               vector<vector<int>>& grid) {
        if (!check(x, y, m, n))
            return 0;
        if (x == 0 && y == 0)
            return grid[x][y];
        if (dp[x][y] != 0)
            return dp[x][y];
        int top = INT_MAX;
        int left = INT_MAX;
        if (check(x - 1, y, m, n))
            top = helper(x - 1, y, m, n, dp, grid);
        if (check(x, y - 1, m, n))
            left = helper(x, y - 1, m, n, dp, grid);
        int minsum = min(top, left);
        return dp[x][y] = minsum + grid[x][y];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // dp[0][0] = grid[0][0];
        // for (int row = 0; row < m; row++) {
        //     for (int col = 0; col < n; col++) {

        //         if (row == 0 && col == 0)
        //             continue;
        //         int top = INT_MAX;
        //         int left = INT_MAX;

        //         if (row > 0)
        //             top = dp[row - 1][col];

        //         if (col > 0)
        //             left = dp[row][col - 1];

        //         dp[row][col] = min(top, left) + grid[row][col];
        //     }
        // }
        // return dp[m - 1][n - 1];
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, INT_MAX);

        dp[0] = 0;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {

                if (col > 0)
                    dp[col] = min(dp[col], dp[col - 1]) + grid[row][col];
                else
                    dp[col] += grid[row][col];
            }
        }

        return dp[n - 1];
        // return helper(m-1,n-1,m,n,dp,grid);
    }
};