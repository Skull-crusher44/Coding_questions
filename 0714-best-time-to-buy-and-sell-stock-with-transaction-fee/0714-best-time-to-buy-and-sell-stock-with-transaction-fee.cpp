class Solution {
private:
    int maxProfitHelper(int idx, bool canBuy, int fee, vector<int> &prices) {
        //Base case
        if(idx == prices.size()) {
            return 0;
        }

        //Explore all possible paths
        int buy = -1e9, sell = -1e9;
        if(canBuy) {
            buy = -prices[idx] + maxProfitHelper(idx + 1, !canBuy, fee, prices);
        } else {
            sell = prices[idx] - fee + maxProfitHelper(idx + 1, !canBuy, fee, prices);
        }
        int move_on = maxProfitHelper(idx + 1, canBuy, fee, prices);
        return max({buy, sell, move_on});
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return maxProfitHelper(0, true, fee, prices);
    }
};