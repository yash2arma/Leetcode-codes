class Solution {
public:
    
    void help(int r, int c, int m, int n, vector<vector<int>>& grid, int &maxi_area, int &sum)
    {
        if(r>=m || r<0 || c>=n || c<0 || grid[r][c]==0 || grid[r][c]==-1)
            return;
        
        sum += grid[r][c];
        grid[r][c] = -1;
        
        help(r, c-1, m, n, grid, maxi_area, sum);
        help(r, c+1, m, n, grid, maxi_area, sum);
        help(r-1, c, m, n, grid, maxi_area, sum);
        help(r+1, c, m, n, grid, maxi_area, sum);
        
        maxi_area = max(maxi_area, sum);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int maxi_area = 0, sum; 
        int m=grid.size(), n=grid[0].size();
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==1)
                {
                    sum = 0;
                    help(i, j, m, n, grid, maxi_area, sum);
                }
            }
        }
        return maxi_area;
        
    }
};