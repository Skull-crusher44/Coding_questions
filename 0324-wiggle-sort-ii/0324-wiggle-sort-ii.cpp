class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans(nums.size(),0);
        int end_index=n-1;
        for(int i=1;i<=(n%2==0?n-1:n-2);i=i+2)
        {
            ans[i]=nums[end_index];
            end_index--;
        }
        for(int i=0;i<=(n%2==0?n-2:n-1);i=i+2)
        {
            ans[i]=nums[end_index];
            end_index--;
        }
        for(int i=0;i<n;i++)
        {
            nums[i]=ans[i];
        }
    }
};