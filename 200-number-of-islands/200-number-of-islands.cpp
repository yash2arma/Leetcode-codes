class Solution 
{
public:  
    
    int dir[5]={-1,0,1,0,-1};
    void bfs(int i, int j, vector<vector<char>>& grid)
    {
        queue<pair<int, int>> q;
        grid[i][j]='0';
        q.push({i, j});
        
        while(!q.empty())
        {
            auto cell = q.front(); 
            q.pop();
            int r=cell.first;
            int c=cell.second;
            
            for(int i=0; i<4; i++)
            {
                int x=r+dir[i];
                int y=c+dir[i+1];
                if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]=='1')
                {
                    grid[x][y]='0';
                    q.push({x, y});
                }
                    
            }
        }
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
                    bfs(i, j, grid);
                }
            }
        }
        return count;
    }
};