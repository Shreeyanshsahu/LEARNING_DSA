class Solution {
bool check(int x ,int y,int m,int n){
    return x<m&&y<n&&x>=0&&y>=0;
}

int helper (int x ,int y,int m,int n,vector<vector<int>>&dp){
    if(x==0&&y==0){
        return 1;
    }
    if(!check(x,y,m,n)){
        return 0;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    int top = 0;
    int left = 0;
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
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=0;
        return helper(m-1,n-1,m,n,dp);
    }
};