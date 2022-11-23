class Solution
{
public:
    /*
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
    */
    
    bool isValidSudoku(vector<vector<char> > &board)
    {
        int r=board.size(), c=board[0].size();
        
        //checking each row;
        for(int i=0; i<9; i++)
        {
            vector<int> row(9, 0);
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(row[board[i][j]-'1'] == 1) return false;
                    else row[board[i][j] - '1'] = 1;
                }
            }
        }
        
        //checking each column
        for(int j=0; j<9; j++)
        {
            vector<int> col(9, 0);
            for(int i=0; i<9; i++)
            {
                if(board[i][j] != '.')
                {
                    if(col[board[i][j]-'1'] == 1) return false;
                    else col[board[i][j] - '1'] = 1;
                }
            }
        }
        
        //checking each 3x3 grid
        vector<int> g1(9, 0), g2(9, 0), g3(9, 0);
        for(int i=0; i<9; i++)
        {
            if((i/3>=0 && i%3==0))
            {
                for(int k=0; k<9; k++)
                {
                    g1[k]=g2[k]=g3[k]=0;
                }
            }

            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(j/3==0)
                    {
                        if(g1[board[i][j]-'1'] == 1)
                        {
                            cout<<i<<" "<<j<<endl;
                            return false;
                        }
                        else g1[board[i][j]-'1'] = 1;
                    }
                    
                    else if(j/3==1)
                    {
                        if(g2[board[i][j]-'1'] == 1)
                        {
                            cout<<i<<" "<<j<<endl;
                            return false;
                        }
                        else g2[board[i][j]-'1'] = 1;
                    }
                    
                    else
                    {
                        if(g3[board[i][j]-'1'] == 1)
                        {
                            cout<<i<<" "<<j<<endl;
                            return false;
                        }
                        else g3[board[i][j]-'1'] = 1;
                    }
                }
            }
        }
        return true;        
    }
};