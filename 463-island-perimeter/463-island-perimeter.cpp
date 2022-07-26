class Solution {
public:
    int dir[5] = {0, -1, 0, 1, 0};
    void perimeter(int r, int c, vector<vector<int>> &grid, int &total)
    {   
        
        for(int k=0; k<4; k++)
        {
            int i = r+dir[k];
            int j= c+dir[k+1];
            if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) continue;
            if(grid[i][j]==1)
                total--;
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int total = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j]==1)
                {
                    total += 4;
                    perimeter(i, j, grid, total);
                }
            }
        }
        return total;
  
    }
};