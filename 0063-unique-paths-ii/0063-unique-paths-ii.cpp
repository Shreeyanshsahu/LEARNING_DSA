class Solution {
    bool check(int x, int y, int m, int n, vector<vector<int>>& grid) {
        return x < m && y < n && x >= 0 && y >= 0 && !grid[x][y];
    }

    int helper(int x, int y, int m, int n, vector<vector<int>>& dp,
               vector<vector<int>>& grid) {
        if (x == 0 && y == 0)
            return 1;
        if (!check(x, y, m, n, grid))
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        int top = 0;
        int left = 0;
        if (check(x - 1, y, m, n, grid)) {
            top = helper(x - 1, y, m, n, dp, grid);
        }
        if (check(x, y - 1, m, n, grid)) {
            left = helper(x, y - 1, m, n, dp, grid);
        }
        return dp[x][y] = top + left;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if (grid[0][0])
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,0);
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // return helper(m-1,n-1,m,n,dp,grid);
        // dp[0][0] = 1;
        // for (int row = 0; row < m; row++) {
        //     for (int col = 0; col < n; col++) {
        //         if (row == 0 && col == 0)
        //             continue;
        //         int top = 0;
        //         int left = 0;
        //         if (grid[row][col] == 1)
        //             continue;
        //         if (row > 0)
        //             top = dp[row - 1][col];

        //         if (col > 0)
        //             left = dp[row][col - 1];

        //         dp[row][col] = top + left;
        //     }
        // }
        // return dp[m - 1][n - 1];
        dp[0] = 1;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0)
                    continue;
                int top = 0;
                int left = 0;
                if (grid[row][col] == 1){
                    dp[col]=0;
                    continue;}
                if (row > 0)
                    top = dp[col];

                if (col > 0)
                    left = dp[col - 1];

                dp[col] = top + left;
            }
        }
        return dp[n - 1];
    }
};