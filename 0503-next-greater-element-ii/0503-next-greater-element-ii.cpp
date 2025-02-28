class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n= nums.size();
        stack<int>s;///store index of numbers
        vector<int> ans(n,-1);
        for(int i =0 ; i < 2*n ; i++)
        {
            while(!s.empty()&&nums[i%n]>nums[s.top()])
            {
                ans[s.top()]=nums[i%n];
                s.pop();
            }
            s.push(i%n);
        }
        return ans;
    }
};