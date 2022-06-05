class Solution {
public:
    int totalNQueens(int n) 
    {
        int ans=0;                 //ans counts toatal no. of possible orders 
        vector<string> board(n);   // create the board of n rows 
        string s(n,'.');           // define column of the board size n=4 i.e. "...." 
        
        for(int i=0;i<n;i++)       // define whole board as a empty string
        {
            board[i]=s;            //["....","....","....","...."]
        }
        
        // we are moving from left to right
        // so we need to check only left part of the current cell because all the cells after current cell (right part) will surely empty
        // we also can not check for upper and lower direction for current cell because each column and row has only one queen
        
        // using hashing for check the collision
        vector<int> leftrow(n,0);                      // maintaining an array left that will tell which row has already taken for placing queen
        vector<int> upperdiagonal(2*n-1,0);          // maintaiing an array upperdiagonal that will tell which upperdiagonal has already taken
        vector<int> lowerdiagonal(2*n-1,0);          // maintaiing an array lowerdiagonal that will tell which lowerdiagonal has already taken
        
        solve(0, board, ans, leftrow, lowerdiagonal, upperdiagonal, n);
        return ans;   
    }
    
    void solve(int col, vector<string> &board, int &ans, 
               vector<int> &leftrow, vector<int> &lowerdiagonal, 
               vector<int> &upperdiagonal, int n)
    {
        //when all columns are covered, we increase the count and return
        if(col == n) 
        {
            ans++;
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            //condition for checking collision, if all satisfy means there is no collision
            if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && 
               upperdiagonal[n-1+row-col]==0)
            {
                board[row][col] = 'Q';
                leftrow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1+row-col]=1;
                solve(col+1, board, ans, leftrow, lowerdiagonal, upperdiagonal, n);
                //backtracking
                board[row][col] = '.'; 
                leftrow[row]=0;
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+row-col]=0;
            }
        }
    }     
};