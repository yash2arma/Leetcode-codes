class Solution 
{
public:
    
    //Memoization
    int help(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(i>=grid.size() || j>=grid[0].size()) return 1e9;
        if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int right = grid[i][j] + help(i, j+1, grid, dp);
        int down = grid[i][j] + help(i+1, j, grid, dp);

        return dp[i][j]=min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        return help(0, 0, grid, dp);
    }
    
    //Tabulation
    /*
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,0));
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else
                {
                    int left=INT_MAX, up=INT_MAX;
                    if(i>0) up = grid[i][j] + dp[i-1][j];
                    if(j>0) left = grid[i][j] + dp[i][j-1];
                    dp[i][j] = min(left, up);
                }
            }
        }
        return dp[m-1][n-1];
    }
    */
    
    /*
    //Space Optimization
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        vector<int> pre(n,0);
        
        for(int i=0; i<m; i++)
        {
            vector<int> cur(n, 0);
            for(int j=0; j<n; j++)
            {
                if(i==0 && j==0) cur[j]=grid[i][j];
                else
                {
                    int left=INT_MAX, up=INT_MAX;
                    if(i>0) up = grid[i][j] + pre[j];
                    if(j>0) left = grid[i][j] + cur[j-1];
                    cur[j] = min(left, up);
                }
            }
            pre = cur;
        }
        return pre[n-1];
    }
    */
};