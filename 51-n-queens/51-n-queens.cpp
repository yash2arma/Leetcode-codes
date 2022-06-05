class Solution {
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        //create a board
        vector<string> board(n);
        string s(n,'.');   //create the cell
        for(int row=0; row<n; row++)
            board[row] = s;
        
        vector<int> leftrow(n), lowerdiagonal(2*n-1), upperdiagonal(2*n-1);
        solve(0, board, ans, leftrow, lowerdiagonal, upperdiagonal, n);
        return ans;   
    }
    
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &leftrow, vector<int> &lowerdiagonal, 
               vector<int> &upperdiagonal, int n)
    {
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && 
               upperdiagonal[n-1+col-row]==0)
            {
                board[row][col] = 'Q';
                leftrow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1+col-row]=1;
                solve(col+1, board, ans, leftrow, lowerdiagonal, upperdiagonal, n);
                board[row][col] = '.'; 
                leftrow[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+col-row]=0;
            }
        }
    }     
};