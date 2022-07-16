class Solution {
public:
    
    long long mod = 1e9 + 7;
    int dp[51][51][51];
    
    int paths(int i, int j, int r, int c, int move)
    {
        if(move<0) return 0;
        
        if(i>=r || i<0 || j>=c || j<0) return 1;
        
        if(dp[i][j][move]!=-1) return dp[i][j][move];
        
        int left = paths(i, j-1, r, c, move-1);
        int right = paths(i, j+1, r, c, move-1);
        int up = paths(i-1, j, r, c, move-1);
        int down = paths(i+1, j, r, c, move-1);
        
        return dp[i][j][move] = (left%mod + right%mod + up%mod + down%mod)%mod;   
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) 
    {
        memset(dp, -1, sizeof(dp));
        return paths(startRow, startColumn, m, n, maxMove);
    }
};