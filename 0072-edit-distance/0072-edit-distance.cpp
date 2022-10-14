class Solution 
{
public:
    int oper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(i<0) return 1+j;
        if(j<0) return 1+i;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j]) return dp[i][j] = oper(i-1, j-1, s, t, dp);
        
        return dp[i][j] = 1 + min({oper(i, j-1, s, t, dp), oper(i-1, j, s, t, dp), oper(i-1, j-1, s, t, dp)});
        
    }
    
    int minDistance(string s, string t) 
    {
        int m=s.size(), n=t.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return oper(m-1, n-1, s, t, dp);
    }
};