class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp(20001);
        unordered_map<int, int> mp;
        for(int i:nums)
        mp[i]++;
        dp[0]=0;
        dp[1]=mp[1];
        for(int i=2;i<20001;i++)
        {
            int include = dp[i-2]+i*mp[i];
            int exclude = dp[i-1];

            dp[i]=max(include,exclude);
        }
        return dp[20000];
    }
};