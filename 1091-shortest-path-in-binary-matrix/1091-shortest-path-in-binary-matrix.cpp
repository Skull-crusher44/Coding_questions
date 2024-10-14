class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)
        return -1;
        int n=grid.size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        grid[0][0]-1;

        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int curr_level=q.front().second;
            q.pop();

            vector<pair<int,int>>destination={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
            for(auto des:destination)
            {
                int row=i+des.first;
                int col=j+des.second;
                if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==0)
                {
                    grid[row][col]=-1;
                    q.push({{row,col},curr_level+1});
                    if(row==n-1&&col==n-1)
                    return curr_level+1;
                }
            }
        }
        return -1;
        
    }
};