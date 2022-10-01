class Solution
{
    public:
        /*int decode(int idx, string s, vector<int> &dp)
        {
            if(idx == s.size()) return 1;

            if(s[idx]=='0') return 0;

            if(dp[idx]!=-1) return dp[idx];

            int res = decode(idx+1, s, dp);

            if(idx < s.size()-1 && (s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6')))
                res += decode(idx+2, s, dp);

            return dp[idx] = res;
        }

        int numDecodings(string s) 
        {
            int n=s.size();
            vector<int> dp(n+1, -1);
            dp[n]=1;
            return decode(0, s, dp);    
        }
        */

        int numDecodings(string s)
        {
            int n = s.size();
            vector<int> dp(n + 1);
            dp[n] = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '0') dp[i] = 0;
                else
                {
                    dp[i] = dp[i + 1];
                    if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1]<'7')) dp[i] += dp[i + 2];
                }
            }
            return dp[0];
        }
};