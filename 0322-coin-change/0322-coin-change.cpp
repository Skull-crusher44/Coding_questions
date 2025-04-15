class Solution {
public:
    int minWays(vector<int>&coins, int amount, int n ){
        //base case
        if(amount==0)return 0;
        else if(n==0) return INT_MAX-1;
        int notTaken = minWays(coins, amount, n-1);
        int taken = INT_MAX-1;
        if(coins[n-1]<=amount)
            taken = 1 + minWays(coins, amount-coins[n-1], n);
        return min(taken,notTaken);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        int ans = minWays(coins,amount,n);
        return ans==INT_MAX-1?-1:ans;    
    }
};