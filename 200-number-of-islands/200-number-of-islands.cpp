class Solution 
{
public:
    
    void help(int i, int j, vector<vector<char>> &grid)
    {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]=='0' || grid[i][j]=='2') return;
        
        grid[i][j]='2';
        help(i, j-1, grid);
        help(i, j+1, grid);
        help(i-1, j, grid);
        help(i+1, j, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int count=0;
        int r=grid.size(), c=grid[0].size();
        
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    help(i, j, grid);
                }
            }
        }
        return count;
    }
};