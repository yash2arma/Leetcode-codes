class Solution 
{
public:
    int decode(int idx, string s, vector<int> &dp)
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
};