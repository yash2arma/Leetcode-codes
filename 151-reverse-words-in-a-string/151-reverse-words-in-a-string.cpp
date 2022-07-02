class Solution {
public:
    string reverseWords(string str) 
    {
        string ans = "";
        int n = str.length();
        int l=n-1;
        string s="";
        while(l>=0)
        {
            if(str[l] == ' ')
            {
                if(s != "")
                {
                    ans += s+' ';
                    s = "";
                }
            }
            else
            {
                char c = str[l];
                s = c+s;
            }
            l--;
        }
        if(s!="")
        { 
            ans = ans+s;
        }
        
        if(ans[ans.size()-1] == ' ')
            ans.erase(ans.size()-1);
        return ans;
        
    }
};