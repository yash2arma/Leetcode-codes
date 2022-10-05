class Solution 
{
public:
    int lcs(string &s, string &t)
    {
        int m=s.size(), n=t.size();
        vector<int> pre(n+1), cur(n+1);
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1]==t[j-1])
                {
                    cur[j] = 1 + pre[j-1];
                }
                else
                {
                    cur[j] = max(pre[j], cur[j-1]);
                }
            }
            pre = cur;
        }
        return pre[n];
    }
    
    int longestPalindromeSubseq(string s) 
    {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);        
    }
};