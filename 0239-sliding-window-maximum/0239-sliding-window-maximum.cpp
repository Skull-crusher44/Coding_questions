class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int n=nums.size();

        if(k==1)
        {
            return nums;
        }
        vector<int>ans(n-k+1,0);
        for(int i=0;i<k;i++)
        {
            maxi=max(maxi,nums[i]);
        }
        ans[0]=maxi;
        for(int i=k;i<n;i++)
        {
            if(nums[i]>=maxi)
            {
                 maxi=nums[i];
            }
            ans[i-k+1]=maxi;   
        }
        return ans;
    }
};