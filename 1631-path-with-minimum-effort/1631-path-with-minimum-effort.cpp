class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0,{0,0}});

        vector<vector<int>>visited(n,vector<int>(m,0));
         while(!q.empty())
        {
            int diff=q.top().first; // maximum abosolute difference till this node 
            int i=q.top().second.first;
            int j=q.top().second.second;
            q.pop();
            //if already visited then continue
            if(visited[i][j])
            continue;
            // if not already visited 
            visited[i][j]=1;
            // poped node => till this currnode we get min effort cost 
            if(i==n-1 && j==m-1)
                return diff;
            vector<pair<int,int>>destination={{-1,0},{0,-1},{0,1},{1,0}};
            for(auto des:destination)
            {
                int row=i+des.first;
                int col=j+des.second;
                
                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col])
                {
                    int new_dif = max(diff,abs(heights[i][j]-heights[row][col]));
                    //effort of path till this neighbour node 
                    q.push({new_dif,{row,col}});
                }
            }
        }
        return 0;
    }
};