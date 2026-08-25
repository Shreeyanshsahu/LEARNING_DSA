class Solution {
    int countstairs(int n,vector<int>&dp){
        if(n<0) return 0;
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];

        return dp[n]=countstairs(n-1,dp)+countstairs(n-2,dp);
    }
public:
    int climbStairs(int n) {
        int prev1=1;
        int prev2=2;
        if(n ==1) return 1;
        if(n ==2) return 2;
        int curr;
        for(int i=3;i<=n;i++){
            curr = prev1+prev2;
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;
    }
};