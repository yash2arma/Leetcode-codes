class Solution 
{
public:
    string largestPalindromic(string num) 
    {
        int cnt[10] = {0};
        for(auto it:num) cnt[it-'0']++;
        string res, res2;
        int t;
        
        for(int i=9; i>=0; i--)
        {
            if(i==0 && res.empty()) break;
            t=cnt[i]/2;
            for(int j=0; j<t; j++) res.push_back('0'+i);
            cnt[i] -= 2*t;
        }
        
        res2 = res;
        reverse(res2.begin(), res2.end());
        
        for(int i=9; i>=0; i--)
        {
            if(cnt[i]) 
            {
                res.push_back('0'+i);
                break;
            }
        }
        return res+res2;
    }
};