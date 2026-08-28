class Solution {
    int helper(int idx, int start, vector<int>& dp, vector<int>& nums) {
        if (idx < start)
            return 0;

        if (idx == start)
            return nums[idx];

        if (dp[idx] != -1)
            return dp[idx];

        int pick = nums[idx] + helper(idx - 2, start, dp, nums);
        int notpick = helper(idx - 1, start, dp, nums);

        return dp[idx] = max(pick, notpick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp(n, -1);

        // Case 1: exclude last house
        int case1 = helper(n - 2, 0, dp, nums);

        fill(dp.begin(), dp.end(), -1);

        // Case 2: exclude first house
        int case2 = helper(n - 1, 1, dp, nums);

        return max(case1, case2);
    }
};