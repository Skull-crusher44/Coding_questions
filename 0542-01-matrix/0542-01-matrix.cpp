class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        queue<pair<int,int>>q;
        for(int i =0 ; i < n ; i++)
        {
            for(int j =0 ; j < m ; j++)
            {
                 if(mat[i][j]==0)
                 q.push({i,j});
                 else 
                 mat[i][j]=-1;
            }
        }
        int dist=0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty())
        {
            int size=q.size();
            dist++;
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(auto dir : directions) {
                    int newRow = i + dir.first, newCol = j + dir.second;
                    if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && mat[newRow][newCol] == -1) {
                        q.push({newRow, newCol});
                        mat[newRow][newCol] = dist; 
                    }
                }
            }
        }
        return mat;
    }
        
};
                