
class Solution 
{
    /*
    private:
        int solve(int ind, string &s, int prev, int k, vector<vector<int>> &dp) 
        {
            if(ind == -1) 
            {
                return 0;
            }

            if(dp[ind][prev] != -1)
                return dp[ind][prev];

            int take = 0;
            int ch = s[ind] - 'a' + 1;

            if (prev == 0 or abs(ch - prev) <= k) 
            {
                take = solve(ind - 1, s, ch, k, dp) + 1;
            }

            int notTake = solve(ind - 1, s, prev, k, dp);
            return dp[ind][prev] = max(take, notTake);
        }
    public:

        int longestIdealString(string s, int k) 
        {

            int n = s.size();
            vector<vector<int>> dp(n, vector<int>(27, -1)); // 27 because space for 26 alphabets and one more for '0';

            return solve(n - 1, s, 0, k, dp);
        }
        */
    
    public:
        int longestIdealString(string s, int k) 
        {
            int n=s.size();
            vector<int> max_chr(26, 0);
            max_chr[s[n-1]-'a'] = 1;
            
            for(int i=n-2; i>=0; i--)
            {
                int lb = max(0, (s[i]-'a')-k);
                int ub = min(25, (s[i]-'a')+k);
                
                int ans=0;
                for(int j=lb; j<=ub; j++)
                    ans = max(max_chr[j], ans);
    
                max_chr[s[i]-'a'] = max(max_chr[s[i]-'a'], ans+1);
            }
            
            int res=0;
            for(int i=0; i<=25; i++)
            {
                res = max(res, max_chr[i]);
            }
            return res;
        }
    
};