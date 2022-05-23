class Solution {
public:
    
    vector<int> count(string s)
    {
        
        vector<int> cnt(2);
        for(auto it: s)
        {
            it=='0' ? cnt[0]++ : cnt[1]++;
        }
        return cnt;
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<int>> dp(m+1, (vector<int> (n+1, 0)));
        
        for(auto s:strs)
        {
            vector<int> cnt = count(s);
            
            for(int zero=m; zero>=cnt[0]; zero--)
            {
                for(int one=n; one>=cnt[1]; one--)
                {
                    dp[zero][one] = max(1+dp[zero-cnt[0]][one-cnt[1]], dp[zero][one]);
                }
            }
        }
        return dp[m][n];
    }
};