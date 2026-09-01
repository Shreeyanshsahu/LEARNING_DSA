class Solution {
bool check(int x ,int y,int m,int n){
    return x<m&&y<n&&x>=0&&y>=0;
}

int helper (int x ,int y,int m,int n,vector<vector<int>>&dp){
    if(x==0&&y==0) return 1;
    if(!check(x,y,m,n))  return 0;
    if(dp[x][y]!=-1)  return dp[x][y];
    int top = 0; int left = 0;
    if(check(x-1,y,m,n)){
        top = helper(x-1,y,m,n,dp);
    }
    if(check(x,y-1,m,n)){
        left = helper(x,y-1,m,n,dp);
    }
    return dp[x][y]=top+left;
}
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n,0);
        dp[0]=1;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0)
                    continue;

                int top = 0;
                int left = 0;

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