class Solution {
public:
    int count(int amount, int n, vector<int>&coins ){
        if(amount==0) // when amount =0 then there will one empty subset whose sum will be zero 
            return 1;
        if(n==0) // here no element is there => there is no way to get a subset whose sum is non zero 
            return 0;
        int notTaken = count(amount,n-1,coins);
        
        int taken = 0;
        if(coins[n-1]<=amount)
        {
            taken = count(amount-coins[n-1], n, coins);
        }

        return taken + notTaken;
        
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        return count(amount,n,coins);      
    }
};