class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //buy at local minimum price and  sell at local max prices
        int n = prices.size();
        int profit =0;
        for(int i = 1 ; i < n ; i++)
        {
            //current price is greater then previous price then add to profit
            if(prices[i]>=prices[i-1]){
                profit += prices[i]-prices[i-1];
            }
        }
        return profit;
    }
};