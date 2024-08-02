class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        
        int total_one=0;
        for(int i=0;i<n;i++) 
        {
            if(nums[i]==1)
            {
                total_one++;
            }
        }

        int wind_count=0;
        for(int i=0;i<total_one;i++)
        {
            if(nums[i]==1)
            wind_count++;
        }

        int swap=wind_count;
        for(int i=0;i<n;i++)
        {
            int no_to_be_add=nums[(i+total_one)%n];
            wind_count = wind_count-nums[i]+no_to_be_add;
            swap=min(swap,total_one-wind_count);
        }

        return swap;
    }
};