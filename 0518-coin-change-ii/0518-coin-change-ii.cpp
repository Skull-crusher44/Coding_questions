class Solution {
public:
    int count(int amount, int n, vector<int>&coins, vector<vector<int>>&memo  ){
        if(amount==0) // when amount =0 then there will one empty subset whose sum will be zero 
            return 1;
        if(n==0) // here no element is there => there is no way to get a subset whose sum is non zero 
            return 0;

        //check in memo
        if(memo[n][amount]!=-1)
            return memo[n][amount];
        int notTaken = count(amount,n-1,coins,memo);
        
        int taken = 0;
        if(coins[n-1]<=amount)
        {
            taken = count(amount-coins[n-1], n, coins,memo);
        }

        return memo[n][amount] = taken + notTaken;
        
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>memo(n+1,vector<int>(amount+1,-1));
        return count(amount,n,coins,memo);      
    }
};