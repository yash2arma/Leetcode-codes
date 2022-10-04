//1. Memoization
class Solution 
{
public:
    int help(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(i==0 || j==0) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i-1]==t[j-1]) return dp[i][j] = 1 + help(i-1, j-1, s, t, dp);

        return dp[i][j] = max(help(i-1, j, s, t, dp), help(i, j-1, s, t, dp));
    }

    int longestCommonSubsequence(string &s, string &t) 
    {
        int m=s.size(), n=t.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        return help(m, n, s, t, dp);
    }
    
};

//2. Tabulation
/*
class Solution 
{
public:
    int longestCommonSubsequence(string s, string t) 
    {
        int m=s.size(), n=t.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i=0; i<=m; i++) dp[i][0] = 0;
        for(int j=0; j<=n; j++) dp[0][j] = 0;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
*/

//3. Space Optimization
/*
class Solution 
{
public:
    int longestCommonSubsequence(string s, string t) 
    {
        int m=s.size(), n=t.size();
        vector<int> pre(n+1, 0) , cur(n+1, 0);

        for(int j=0; j<=n; j++) pre[j] = 0;

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1]==t[j-1])
                    cur[j] = 1 + pre[j-1];
                else
                    cur[j] = max(pre[j], cur[j-1]);
            }
            pre = cur;
        }
        return pre[n];
    }
};
*/