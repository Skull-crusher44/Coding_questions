class Solution {
public:
    bool backtrack(vector<vector<char>>&board, string word, int n, int m, int i, int j,int index){
        
        // If the word is completely matched
        if(index==word.size())return true ;

        // Out-of-bounds or character mismatch
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[index]) return false;

        // store the current character so that it can be again put at (i,j) after backtracking
        int lostChar = board[i][j];
     
            //Logic
        // Store current character and mark cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // All 4 directions
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto [dx, dy] : dirs) {
            if(backtrack(board, word,n,m, i + dx, j + dy, index + 1))
                return true;
        }

        // Backtrack
        board[i][j] = temp;
        // if nothing matches then return false 
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();
        // Har kisi ko starting element man ke bfs lagana ha  
        for(int i =0 ; i < n ; i++)
        {
            for(int j=0;j<m;j++){
                if(backtrack(board,word,n,m,i,j,0))return true;
            }
        }
        return false;
    }
};