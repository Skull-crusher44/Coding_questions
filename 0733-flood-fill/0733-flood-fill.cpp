class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        ans=image;
        q.push({sr,sc});
        if(image[sr][sc]==color)
        return image;
        ans[sr][sc]=color;
        vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(pair dir:direction)
            {
                int row=i+dir.first;
                int col=j+dir.second;
                if(row>=0 && row<n && col>=0 && col<m && image[row][col]==image[i][j] && ans[row][col]!=color)
                {
                    q.push({row,col});
                    ans[row][col]=color;
                }

            }
        }        
        return ans;

    }
};