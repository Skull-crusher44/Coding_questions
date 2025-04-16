class Solution {
public:
    int count(int amount, int index, vector<int>&coins, vector<vector<int>>&memo  ){
        if(amount==0) // when amount =0 then there will one empty subset whose sum will be zero 
            return 1;
        if(index==0) // only one element is there { i=0=> 4, amount=5 =>0 } , { i=0=> 4, amount=12 =>1 } 
            {
                if(amount%coins[index]==0) return 1;
                else return 0;
            }

        //check in memo
        if(memo[index][amount]!=-1)
            return memo[index][amount];
        int notTaken = count(amount,index-1,coins,memo);
        
        int taken = 0;
        if(coins[index]<=amount)
        {
            taken = count(amount-coins[index], index, coins,memo);
        }

        return memo[index][amount] = taken + notTaken;
        
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>memo(n,vector<int>(amount+1,-1));
        return count(amount,n-1,coins,memo);      
    }
};