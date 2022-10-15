class Solution 
{
public:
    //1(a). Memoization - 0 based indexing
    /*
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
    */
    
    //1(b). Memoization - 1 based indexing
    /*
    bool f(int i, int j, string &p, string &t, vector<vector<int>> &dp)
    {
        if(i==0 && j==0) return true;
        if(i==0 && j>0) return false;
        if(j==0 && i>0)
        {
            for(int k=1; k<=i; k++)
                if(p[k-1]!='*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        
        
        if(p[i-1]==t[j-1] || p[i-1]=='?')
            return dp[i][j] = f(i-1, j-1, p, t, dp);
        
        if(p[i-1]=='*')
            return dp[i][j] = f(i-1, j, p, t, dp) | f(i, j-1, p, t, dp);
        
        return dp[i][j] = false;
    }
    
    
    bool isMatch(string s, string p) 
    {
        int m=s.size(), n=p.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return f(n, m, p, s, dp);
    }
    */
    
    //2. Tabulation
    /*
    bool isMatch(string s, string p) 
    {
        int n=s.size(), m=p.size();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        
        dp[0][0]=true;
        for(int j=1; j<=n; j++)
            dp[0][j] = false;
        
        for(int i=1; i<=m; i++)
        {
            int flag = true;
            for(int ii=1; ii<=i; ii++)
            {
                if(p[ii-1] != '*') 
                {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }
        
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                 
                if(p[i-1]==s[j-1] || p[i-1]=='?')
                    dp[i][j] = dp[i-1][j-1];

                else if(p[i-1]=='*')
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                else
                    dp[i][j] = false;
        
            }
            
        }
        return dp[m][n];
    }
    */
    
    //3. Space Optimization
    bool isMatch(string s, string p) 
    {
        int n=s.size(), m=p.size();
        vector<bool> pre(n+1, false), cur(n+1, false);
        
        pre[0]=true;
        
        for(int j=1; j<=n; j++)
            pre[j] = false;
        
        
        for(int i=1; i<=m; i++)
        {
            //Since in tabulation, we update 1st column of each row
            //here, we update 0th index of cur
            int flag = true;
            for(int ii=1; ii<=i; ii++)
            {
                if(p[ii-1] != '*') 
                {
                    flag = false;
                    break;
                }
            }
            cur[0] = flag;
            
            for(int j=1; j<=n; j++)
            {
                 
                if(p[i-1]==s[j-1] || p[i-1]=='?')
                    cur[j] = pre[j-1];

                else if(p[i-1]=='*')
                    cur[j] = pre[j] | cur[j-1];
                else
                    cur[j] = false;
        
            }
            pre = cur;
            
        }
        return pre[n];
    }
    
};