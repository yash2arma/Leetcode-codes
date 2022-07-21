class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        vector<int> dir = {0,1,0,-1,0};
        int m=grid.size(), n=grid[0].size();
        queue<pair<int, int>> q;
        int fresh=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]==2) q.push({i,j});
                
                if(grid[i][j]==1) fresh++;
            }
        }
        
        int ans=-1;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                auto [r,c] = q.front(); q.pop();
                
                for(int j=0; j<4; j++)
                {
                    int cur_r = r+dir[j];
                    int cur_c = c+dir[j+1];
                    
                    if(cur_r<0 || cur_c<0 || cur_r==m || cur_c==n || grid[cur_r][cur_c]==0 || grid[cur_r][cur_c]==2) continue;
                    
                    grid[cur_r][cur_c] = 2;
                    q.push({cur_r, cur_c});
                    fresh--;
                }
            }
            ans++;
        }
        
        if(fresh > 0) return -1;
        if(ans == -1) return 0;
        return ans;           
    }
};