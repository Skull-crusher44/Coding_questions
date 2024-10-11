class Solution {
public:
    void dfs(int start, vector<int>adj[], vector<bool>&visited, vector<int>&ans,int &index)
    {
        visited[start]=true;

        for(auto ele:adj[start])
        {
            if(!visited[ele])
            dfs(ele,adj,visited,ans,index);
        }
        ans[index--]=start;
    }
    vector<int> findOrder(int v, vector<vector<int>>& pre) {
        vector<int>ans(v,0);
        vector<bool>visited(v,false);
        vector<int>adj[v];
        int index=v-1;
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            dfs(i,adj,visited,ans,index);
        }
        return ans;
    }
};