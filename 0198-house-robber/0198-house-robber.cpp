class Solution {
    int helper(int idx,vector<int>&dp,vector<int>&nums){
        if(idx==0) return dp[idx]=nums[idx];
        if(idx<0) return 0;
        if(dp[idx]!=INT_MIN) return dp[idx];
        int pick = nums[idx]+helper(idx-2,dp,nums);
        int notpick = helper(idx-1,dp,nums);
        return dp[idx]=max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int prev1=nums[0];
        int prev2=0;
        for(int i =1;i<nums.size();i++){
            int pick = nums[i];
            int nonpick = prev1;
            if(i>1){
                pick+=prev2;
            }
            int curr = max(pick,nonpick);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};