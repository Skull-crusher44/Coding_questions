class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         queue<pair<int,int>> q;
        int rows = grid.size(), cols = grid[0].size(), timer = 0;
        
        // Push initial rottnened (oranges) positions
        for(int i = 0; i < rows; i++) 
            for(int j = 0; j < cols; j++) 
                if(grid[i][j] == 2) 
                    q.push({i, j});
        
        // Direction vectors for up, down, left, right movements
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!q.empty()) {
            int size = q.size();
            bool spread = false;  // Track if rotttening spreads this round
            
            for(int i = 0; i < size; i++) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                
                // Check 4 possible directions (up, down, left, right)
                for(auto dir : directions) {
                    int newRow = row + dir.first, newCol = col + dir.second;
                    if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 2;  // rotten
                        spread = true;
                    }
                }
            }
            
            if(spread) timer++;  // Only increment timer if rotttening spread
        }
            for(auto &row : grid) //find if there any fresh orange remain
            if(find(row.begin(), row.end(), 1) != row.end()) 
                return -1;
        
            return timer;
    }
};