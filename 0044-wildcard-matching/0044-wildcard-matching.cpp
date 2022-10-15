class Solution 
{
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0)
        {
            for(int k=0; k<=i; k++)
                if(s[k]!='*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(s[i]==p[j] || s[i]=='?')
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        
        if(s[i]=='*')
            return dp[i][j] = f(i-1, j, s, p, dp) | f(i, j-1, s, p, dp);
        
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) 
    {
        int n=s.size(), m=p.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return f(m-1, n-1, p, s, dp);
    }
};