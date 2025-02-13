class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int,int> mp;
        int prefix_sum=0,ans=0;
        mp[0] = 1;
        for(auto it:nums){
            prefix_sum += it;
    
            if(mp.find( prefix_sum - k) != mp.end()){
                ans += mp[ prefix_sum - k]; // jitne bhi prefix_sum-k present honge unki frequency add ho jayegi 
            }
            mp[prefix_sum]++; //agar prefix sum dusri bar aaya ha to uski frequency bdha do
        }
        return ans;
    }
};