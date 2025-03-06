class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count_zero=0;
        int left=0,right=0,max_len=0;
        while(right<nums.size()){
            if(nums[right]==0)
                count_zero++;
            while(count_zero > k)// reset the window so that it must contain k zeros(for flip) by shifting the left pointer 
            {
                if(nums[left]==0)
                count_zero--;
                left++;
            }
            max_len=max(max_len,right-left+1);
            right++;
        }
        return max_len;
    }
};