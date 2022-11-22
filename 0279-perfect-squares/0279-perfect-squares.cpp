class Solution 
{
public:
    
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
};