class Solution 
{
public:
    
    int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool find(int i, int j, int idx, vector<vector<char>>& board, string word)
    {
        if(idx == word.size()) return true;
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[idx]) return false;
        
        char temp = board[i][j];
        board[i][j] = '*';
        
        bool res;
        for(int k=0; k<4; k++)
        {
            int r=i+dir[k][0];
            int c=j+dir[k][1];
            
            res = res || find(r, c, idx+1, board, word);
        }
        board[i][j] = temp;
        
        return res;
    }
        
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == word[0] && find(i, j, 0, board, word))
                   return true;
            }
        }
        return false;
    }
};