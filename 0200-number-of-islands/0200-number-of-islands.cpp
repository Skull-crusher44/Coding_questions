class Solution {
public:
    int find(vector<vector<char>>& grid, int row, int col) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row, col});
        grid[row][col] = '2';  // Mark as visited with '2' instead of '-1'
        
        while (!q.empty()) {
            int row_no = q.front().first;
            int col_no = q.front().second;
            q.pop();
            
            // Check all 4 directions (up, down, left, right)
            vector<pair<int,int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto dir : directions) {
                int new_row = row_no + dir.first;
                int new_col = col_no + dir.second;
                
                // Check boundaries and if the cell is '1'
                if (new_row >= 0 && new_row < rows && new_col >= 0 && new_col < cols && grid[new_row][new_col] == '1') {
                    grid[new_row][new_col] = '2';  // Mark as visited
                    q.push({new_row, new_col});
                }
            }
        }
        return 1;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    count += find(grid, i, j);  // Explore the island
                }
            }
        }
        return count;
    }
};
