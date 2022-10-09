class Solution 
{
public:
    int mod = 1e9+7;
    int help(int i, int j, int sum, int &k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if(i<0 || j<0) return 0;
        
        if(i==0 && j==0) return (sum + grid[0][0])%k==0;
        
        if(dp[i][j][sum]!=-1) return dp[i][j][sum];
        
        int top = help(i-1, j, (sum+grid[i][j])%k, k, grid, dp);
        
        int left = help(i, j-1, (sum+grid[i][j])%k, k, grid, dp);
        
        return dp[i][j][sum]=(top+left)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int m=grid.size(), n=grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (k, -1)));
        int ans = help(m-1, n-1, 0, k, grid, dp);
        return ans;
    }
};
