/*class Solution {
    
    string pali_subs(string &s, int L, int R)
    {
        int n=s.size();
        while(L>=0 && R<n) //iterate until cross the boundary
        {
            if(s[L]!=s[R]) break;
            L--;
            R++;
        }
        return s.substr(L+1, R-1-L);
    }
    
    void long_subs(string &s, string &res, int &lenMax)
    {
        if(s.size()>lenMax)
        {
            res = s;
            lenMax = s.size();
        }
    }
public:
    string longestPalindrome(string s) 
    {
        int lenMax = 0;
        string res;
        
        for(int i=0; i<s.length(); i++)
        {
            string odd = pali_subs(s, i, i); //start from same index for odd length palindrome
            long_subs(odd, res, lenMax);
            string even = pali_subs(s, i, i+1); //start from adjacent index for even length palindrome
            long_subs(even, res, lenMax);
        }
        return res;
    }
};
*/

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n=s.size();
        
        vector<vector<bool>> dp(n, vector<bool> (n,false));
        
        int start=0, lenMax=1;
        
        for(int i=0; i<n; i++) dp[i][i]=true;
        
        for(int i=0; i<n-1; i++) 
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1] = true;
                start = i;
                lenMax = 2;
            }
        }
        
        for(int k=3; k<=n; k++)
        {
            for(int i=0; i<n-k+1; i++)
            {
                int j=i+k-1;
                
                if(dp[i+1][j-1]==true && s[i]==s[j])
                {
                    dp[i][j] = true;
                    
                    if(k>lenMax)
                    {
                        lenMax = k;
                        start=i;
                    }
                }
            }
        }
        
        return s.substr(start, lenMax);
    }
};