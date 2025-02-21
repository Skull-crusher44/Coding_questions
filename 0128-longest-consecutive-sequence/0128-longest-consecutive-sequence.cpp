class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        map<int,int>mp;
        for(int i =0 ; i <nums.size()  ; i++)
        {
            mp[nums[i]]++;
        }
        int prev=-2;
        int count=1,max_count=INT_MIN;
        for(auto &i:mp){
            if(prev==i.first-1)
            count++;
            else
            {
                count=1;
            }
            max_count=max(max_count,count);
            prev=i.first;
        }
    return max_count;
    }
};