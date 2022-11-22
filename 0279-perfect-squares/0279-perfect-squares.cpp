class Solution 
{
public:
    
    //1. Memoization
    /*
    int solve(int n, vector<int> &dp)
    {
        if(n==0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int minSteps = INT_MAX;
        for(int i=1; i<=sqrt(n); i++)
        {
            int sqr = i*i;
            int steps = 1 + solve(n-sqr, dp);
            minSteps = min(minSteps, steps);
        }
        return dp[n] = minSteps;
    }
    
    int numSquares(int n) 
    {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
    */
    
    //2. Tabulation
    int numSquares(int n) 
    {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        
        for(int i=1; i<=n; i++)
        {
            int minSteps = INT_MAX;
            for(int j=1; j<=sqrt(i); j++)
            {
                int sqr = j*j;
                int steps = 1 + dp[i-sqr];
                minSteps = min(minSteps, steps);
            }
            dp[i] = minSteps;
        }
        return dp[n];
    }
};