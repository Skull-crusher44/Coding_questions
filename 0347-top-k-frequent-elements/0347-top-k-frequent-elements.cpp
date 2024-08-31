class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>mp;
        vector<int>ans;
        for(int x:nums)
        {
            mp[x]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto it:mp)
        {
            q.push({it.second,it.first});
        }
        for(int i=0;i<k;i++)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;

    }

};