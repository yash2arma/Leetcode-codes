#define ll long long

ll dp[10001][11][11][6];

class Solution 
{
public:
    ll mod = 1e9+7;
    
    ll dfs(int idx, int first, int second, int i, string &s)
    {
        if(i==5) return 1; //fount 5 digit palindromic number
        if(idx==s.size()) return 0;
        if(dp[idx][first][second][i]!=-1) return dp[idx][first][second][i];
        
        //option for not choosing currect digit
        ll res = dfs(idx+1, first, second, i, s);
        
        if(i==0)
        {
            //option for choosing first digit
            res += dfs(idx+1, s[idx]-'0', second, i+1, s);
            res %= mod;
        }
        
        else if(i==1)
        {
            //option for choosing second digit
            res += dfs(idx+1, first, s[idx]-'0', i+1, s);
            res %= mod;
        }
        
        else if(i==2)
        {
            //option for choosing thirst digit
            res += dfs(idx+1, first, second, i+1, s);
            res %= mod;
        }
        
        else if(i==3)
        {
            //option for choosing fourth digit if digit is equal to second digit
            if(s[idx]-'0' == second)
            {
                res += dfs(idx+1, first, second, i+1, s);
                res %= mod;
            }
        }
        
        else if(i==4)
        {
            //option for choosing fifth digit if digit is equal to first digit   
            if(s[idx]-'0' == first)
            {
                res += dfs(idx+1, first, second, i+1, s);
                res %= mod;
            }
        }
        return dp[idx][first][second][i] = res;
    }
    
    int countPalindromes(string s) 
    {
        memset(dp, -1, sizeof dp);
        return dfs(0, 10, 10, 0, s);
    }
};