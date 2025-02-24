class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int l= 0,h=n-1;
        int ans=nums[0];
        while(l<=h){

            int mid= l+(h-l)/2;

            if(nums[mid]==nums[l]&&nums[mid]==nums[h]){
                ans=min(ans,nums[mid]);
                h--;
                l++;
            }
            else if (nums[mid]>=nums[l]){
                ans=min(ans,nums[mid]);
                l=mid+1;
            }
            else
                {
                    ans=min(ans,nums[mid]);
                    h=mid-1;
                }
        }
        return ans;
    }
};