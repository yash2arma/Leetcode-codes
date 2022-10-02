class Solution
{
    public:
        int mod = 1e9+7;
    
//     int numRollsToTarget(int n, int k, int target)
//     {
//         vector<vector<int>> dp(n+1, vector<int> (target+1, 0));
//         dp[0][0] = 1;
        
//         for(int i=1; i<=n; i++)
//         {
//             for(int t=0; t<=target; t++)
//             {
//                 for(int j=1; j<=k; j++)
//                 {
//                     if(j<=t)
//                         dp[i][t] = (dp[i][t]%mod + dp[i-1][t-j]%mod)%mod;
//                 }
//             }
//         }
//         return dp[n][target]%mod;
//     }
    
    
    int help(int i, int &k, int tar, vector<vector<int>> &dp)
    {
        if (i==0)
        {
            return tar==0 ? 1:0;
        }

        if (dp[i][tar] != -1) return dp[i][tar];
        int take = 0;
        
        for (int n=1; n<=k; n++)
        {
            if (n <= tar)
                take = (take%mod + help(i-1, k, tar-n, dp)%mod) % mod;
        }

        return dp[i][tar] = take%mod;
    }

    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return help(n, k, target, dp) % mod;
    }
    
};