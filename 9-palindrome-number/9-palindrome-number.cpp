class Solution {
public:
    bool isPalindrome(int x) 
    {
        string s = to_string(x);
        int l=0, h=s.size()-1;
        
        while(l<h)
        {
            if(s[l]==s[h])
            {
                l++;
                h--;
            }
            else
                return false;
        }
        return true;
        
        
    }
};