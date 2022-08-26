
class Solution 
{
public:
    
    //Memoizaton
    int f(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        if(j<0 || j>=mat[0].size()) return 1e8;
        if(i==0) return mat[0][j];
        if(dp[i][j] != -1) return dp[i][j];

        int u=mat[i][j] + f(i-1, j, mat, dp);
        int ld=mat[i][j] + f(i-1, j-1, mat, dp);
        int rd=mat[i][j] + f(i-1, j+1, mat, dp);

        return dp[i][j] = min(u, min(ld, rd));
    }

    int minFallingPathSum(vector<vector<int>> &mat)
    {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int mini=1e8;
        for(int j=0; j<n; j++)
            mini = min(mini, f(m-1, j, mat, dp));
        return mini;
    }
    
    //Tabulation
    /*int minFallingPathSum(vector<vector<int>> &mat)
    {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));

        for(int j=0; j<n; j++) dp[0][j] = mat[0][j];

        for(int i=1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                int u = mat[i][j] + dp[i-1][j];
                int ld = mat[i][j], rd = mat[i][j];

                if(j-1>=0) ld += dp[i-1][j-1];
                else ld += 1e8;

                if(j+1<n) rd += dp[i-1][j+1];
                else rd += 1e8;

                dp[i][j] = min(u, min(ld, rd));
            }
        }

        int mini=1e8;
        for(int j=0; j<n; j++)
            mini = min(mini, dp[m-1][j]);
        return mini;
    }
    */
    
    //Space Optimization
    /*
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
        int r=mat.size(), c=mat[0].size();
        vector<int> pre(c, 0), cur(c, 0);
        
        for(int j=0; j<c; j++) pre[j] = mat[0][j];
        
        for(int i=1; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                int u = mat[i][j] + pre[j];
                
                int ld=mat[i][j], rd=mat[i][j];
                
                if(j-1>=0) ld += pre[j-1];
                else ld += 1e8;
                
                if(j+1<c) rd += pre[j+1];
                else rd += 1e8;
                    
                cur[j] = min(u, min(ld, rd));
            }
            pre = cur;
        }
        
        int mini = 1e8;
        for(int j=0; j<c; j++)
            mini = min(mini, pre[j]);
        
        return mini;
        
    }
    */
};


