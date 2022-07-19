class Solution {
public:
    
    /*void help(int r, int c, int m, int n, vector<vector<int>>& grid, int &maxi_area, int &sum)
    {
        if(r>=m || r<0 || c>=n || c<0 || grid[r][c]<=0)
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
    */
    
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int r=grid.size(), c=grid[0].size(), max_area=0;
        
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                if(grid[i][j] == 1)
                    max_area = max(max_area, get_area(grid, i, j));
        return max_area;
    }
    
    int get_area(vector<vector<int>> & grid, int i, int j)
    {
        if(i<0 || j<0 || i>= grid.size() || j>=grid[0].size() || grid[i][j] <= 0)
            return 0;
        
        grid[i][j] = -1;
        int leftarea = get_area(grid, i-1, j);
        int rightarea = get_area(grid, i+1, j);
        int toparea = get_area(grid, i, j-1);
        int bottomarea = get_area(grid, i, j+1);
        
        int totalarea = leftarea+rightarea+toparea+bottomarea;
        return 1+ totalarea;
    }
};