class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<pair<int,pair<int,int>>>arr;
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            arr.push_back({matrix[i][0],{i,0}});
        }
        priority_queue
        <        pair<int,pair<int,int>>
         ,vector<pair<int,pair<int,int>>>
         ,greater<pair<int,pair<int,int>>>
        >        q(arr.begin(),arr.end());

        int ans=-1;
        while(k--)
        {
            int value=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
            q.pop();
            ans=value;
            if(col+1<n)
            q.push({matrix[row][col+1],{row,col+1}});
        }
        return ans;
    }
};