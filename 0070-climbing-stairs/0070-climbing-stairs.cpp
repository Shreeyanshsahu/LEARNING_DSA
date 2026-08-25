class Solution {
    int countstairs(int n,vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];

        return dp[n]=countstairs(n-1,dp)+countstairs(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return countstairs(n,dp);
    }
};