class Solution {
public:
    int removePalindromeSub(string s) 
    {
        int f=0, e=s.size()-1;
      
        while(f<e)
        {
            if(s[f]!=s[e]) return 2;
            f++;
            e--;
        }
        return 1;
    }
};