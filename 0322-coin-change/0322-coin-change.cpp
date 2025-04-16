class Solution {
public:
    int minWays(vector<int>&coins, int amount, int n ){
        // Base cases
        if (amount == 0) return 0;
        if (n == 0) return INT_MAX;

        int notTaken = minWays(coins, amount, n - 1);
        int taken = INT_MAX;

        if (coins[n - 1] <= amount) {
            int res = minWays(coins, amount - coins[n - 1], n);
            if (res != INT_MAX) {
                taken = 1 + res;
            }
        }

        return min(taken, notTaken);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX));
        dp[0][0]=0;
        //intialize first row considering first element when i=0 (coins[0]) with 0<=j<=amount
        // 0 1 2 3 4 5 6 7 8 9 10 11
        // 0 1 2 3 4 5 6 7 8 9 10 11
        // for(int i=0;i<=amount;i++){
        //     if(i%coins[0]==0){
        //         dp[0][i]=i/coins[0];
        //     }
        // }

        for(int i =1 ; i<=n ; i++)
        {
            for(int j=0;j<=amount;j++){
                int notTaken = dp[i-1][j];
                int taken=INT_MAX;
                if(coins[i-1]<=j){
                    taken = dp[i][j-coins[i-1]];
                    if(taken!=INT_MAX)taken+=1;
                }
                dp[i][j] = min(taken,notTaken);
            }
        } 
        
        return dp[n][amount]==INT_MAX?-1:dp[n][amount];    
    }
};