class Solution {
    int mod = (int)1e9+7;
public:
    int findWays(vector<int> &nums , int target){
        int n= nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
        dp[0][0]=1;

        for(int i =1 ; i <= n ; i++)
        {
            for(int j =0 ; j <=target ; j++)
            {
                int exclude = dp[i-1][j];

                int include=0;
                if(nums[i-1]<=j){
                    include = dp[i-1][j-nums[i-1]];
                }
                dp[i][j] = (include + exclude)%mod;
            }
        }
        return dp[n][target]%mod;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum=0;
        for(int num:nums){
            total_sum+=num;
        }

        //let two subset posSum,negSum where posSum contain all positive no and negSum contain all negative no 
        //posSum+negSum == target
        // posSum - (abs(negSum)) == target taking minus sign common from negative terms 
        // s1-s2 = d(target) => s1 = (Range-d)/2
        // count no of subsets having sum == (Range-d)/2

        int Range = total_sum;
        int d = target;
        if(Range-d<0||(Range-d)%2==1)return 0;
        return findWays(nums,(Range-d)/2);
    }
};