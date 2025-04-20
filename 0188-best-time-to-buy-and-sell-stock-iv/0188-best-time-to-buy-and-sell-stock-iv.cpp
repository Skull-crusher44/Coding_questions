class Solution {
public:
    // Tabulation - O(N * 2 * K) time and space
    int solveTab(vector<int> &prices, int k) {
        int n = prices.size();

        // dp[index][buy][limit]
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int limit = 1; limit <= k; limit++) {
                    int profit = 0;

                    if (buy) {
                        int Buy = -prices[index] + dp[index + 1][0][limit];
                        int skip = dp[index + 1][1][limit];
                        profit = max(Buy, skip);
                    } else {
                        int sell = prices[index] + dp[index + 1][1][limit - 1];
                        int skip = dp[index + 1][0][limit];
                        profit = max(sell, skip);
                    }

                    dp[index][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][k]; // Start from day 0, canBuy = 1, k transactions allowed
    }

    int maxProfit(int k, vector<int>& prices) {
        return solveTab(prices, k);
    }
};
