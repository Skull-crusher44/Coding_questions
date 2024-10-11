class Solution {
public:
 void dfs(int i,int j, int n, int m, vector<vector<char>>&board)
    {
        board[i][j]='T';
        // traverse through neighbour in four directions
        int roo[]={-1,0,0,1};
        int coo[]={0,-1,1,0};
        
        for(int k=0;k<4;k++)
        {
            int row=i+roo[k];
            int col=j+coo[k];
            if(row>=0 && row<n && col>=0 && col<m && board[row][col]=='O')
            {
                dfs(row,col,n,m,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        //first row
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                dfs(0,j,n,m,board);
            }
        }
        //last row
        for(int j=0;j<m;j++)
        {
            if(board[n-1][j]=='O')
            {
                dfs(n-1,j,n,m,board);
            }
        }
        //first column
        for(int i=1;i<n-1;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(i,0,n,m,board);
            }
        }
        //last column
        for(int i=1;i<n-1;i++)
        {
            if(board[i][m-1]=='O')
            {
                dfs(i,m-1,n,m,board);
            }
        }
        // replace 'O'to 'X' and 'T'to'O'
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                board[i][j]='X';
                else if(board[i][j]=='T')
                board[i][j]='O';
            }
        }
        
    }
};