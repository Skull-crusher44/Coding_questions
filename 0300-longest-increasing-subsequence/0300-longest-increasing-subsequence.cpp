class Solution {
public:
    int lis(vector<int>& nums, int curr, int prev_index, vector<vector<int>>& dp) {
        if (curr == 0) return 0;

        if (dp[curr][prev_index] != -1)
            return dp[curr][prev_index];

        int notTaken = lis(nums, curr - 1, prev_index, dp);
        int taken = 0;
        if (nums[curr - 1] < nums[prev_index]) {
            taken = 1 + lis(nums, curr - 1, curr - 1, dp);
        }

        return dp[curr][prev_index] = max(taken, notTaken);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(INT_MAX);

        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        return lis(nums, n, n,dp);
    }
};