class Solution {
public:
/*
    when we iterate till n means last element, now if we consider last element then 
    we will not consider last second and first element. here i am  subtracting the first element*/
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==2)return 0; 

        vector<int>ans(n+1,0);
        ans[0]=0;
        ans[1]=nums[0];
        for(int i=2;i<=n;i++){
            int consider = ans[i-2]+nums[i-1]-((i==n)?nums[0]:0);
            //problem in above line 
            /*You're thinking:
            "If I include the last house, then subtract the value of the first house to handle the circular case."
            This seems intuitive, but it doesn’t prevent the first house from being included earlier in the DP computation.
            */
            int notConsider = ans[i-1];
            ans[i] = max(consider,notConsider);
        }
        return ans[n];
    }
}; 
