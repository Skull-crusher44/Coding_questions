class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>map;
        for(int i:nums){
            if(i<k)return -1;
            else if(i>k){
                map[i]++;
            }
        }
        
        return map.size();
    }
};