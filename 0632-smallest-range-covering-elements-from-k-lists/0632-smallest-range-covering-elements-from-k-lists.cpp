class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,pair<int,int>>>temp;
        int minimum=INT_MAX;
        int maximum = INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back({nums[i][0],{i,0}});
            maximum=max(nums[i][0],maximum);
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q(temp.begin(),temp.end());

        vector<int>ans(2,0);
        ans[0]=q.top().first;
        ans[1]=maximum;

        while(q.size()==nums.size())
        {
            int value=q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();
            if(col+1<nums[row].size())
            {
                col++;
                q.push({nums[row][col],{row,col}});
                maximum=max(maximum,nums[row][col]);
                minimum=q.top().first;
                if(maximum-minimum < ans[1]-ans[0])
                {
                    ans[0]=minimum;
                    ans[1]=maximum;
                }
            }
        }
        return ans;
    }
};