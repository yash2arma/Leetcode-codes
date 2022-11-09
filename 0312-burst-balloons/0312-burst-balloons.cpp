class Solution 
{
public:
    //1. Memoization
    /*
    int f(int i, int j, vector<int> &a, vector<vector<int>> &dp)
    {
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int maxi=INT_MIN;
        for(int idx=i; idx<=j; idx++)
        {
            int coins = a[i-1]*a[idx]*a[j+1] + f(i, idx-1, a, dp) + f(idx+1, j, a, dp);
            maxi = max(maxi, coins);
        }
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& a) 
    {
        int n=a.size();
        a.push_back(1);
        a.insert(a.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return f(1, n, a, dp);
        
    }
    */
    
    //2. Tabulation
    int maxCoins(vector<int>& a) 
    {
        int n=a.size();
        a.push_back(1);
        a.insert(a.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int i=n; i>=1; i--)
        {
            for(int j=i; j<=n; j++)
            {
                int maxi=INT_MIN;
                for(int idx=i; idx<=j; idx++)
                {
                    int coins = a[i-1]*a[idx]*a[j+1] + dp[i][idx-1] + dp[idx+1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;

            }
        }
        return dp[1][n];
        
    }
};