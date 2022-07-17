class Solution {
public:
    
    int kInversePairs(int n, int k) 
    {
        int dp[1001][1001] = {1};
        int mod = 1e9+7;
        
        for(int i=1; i<=n; i++)
        {
            for(int K=0; K<=k; K++)
            {
                for(int j=0; j<=min(K, i-1); j++)
                {
                    dp[i][K] = (dp[i][K] + dp[i-1][K-j])%mod;
                }
            }
        }
        return dp[n][k];
                 
    }
};