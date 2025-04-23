class Solution {
public:
    int lis(vector<int>& nums, int curr, int prev, vector<vector<int>>& dp) {
        if (curr == 0) return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        int notTaken = lis(nums, curr - 1, prev, dp);
        int taken = 0;
        if (prev == -1 || nums[curr - 1] < nums[prev]) {
            taken = 1 + lis(nums, curr - 1, curr - 1, dp);
        }

        return dp[curr][prev + 1] = max(taken, notTaken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return lis(nums, n, -1,dp);
    }
};