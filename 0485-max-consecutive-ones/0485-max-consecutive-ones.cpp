class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int max_length=0;
        int index=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                max_length=max(max_length,(i-index-1));
                index=i;
            }
        }
        max_length=max(max_length,(n-index-1));
        return max_length;
    }
};