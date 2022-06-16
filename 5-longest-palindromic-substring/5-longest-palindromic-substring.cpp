class Solution {
    
    string pali_subs(string &s, int L, int R)
    {
        int n=s.size();
        while(L>=0 && R<n)
        {
            if(s[L]!=s[R]) break;
            L--;
            R++;
        }
        return s.substr(L+1, R-1-L);
    }
    
    void longest(string &s, string &res, int &lenMax)
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
            string odd = pali_subs(s, i, i);
            longest(odd, res, lenMax);
            string even = pali_subs(s, i, i+1);
            longest(even, res, lenMax);
        }
        return res;
    }
};