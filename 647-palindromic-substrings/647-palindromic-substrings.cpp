class Solution {
public:
    
    
    int countSubstrings(string s) 
    {
        int beg, end, count=0, n=s.size();
        
        for(int i=0; i<n; i++)
        {
            beg=i; end=i;
            while(beg>=0 && end<n && s[beg--]==s[end++]) count++;
            
            beg=i-1; end=i;
            while(beg>=0 && end<n && s[beg--]==s[end++]) count++;
        }
        
        return count;
    }
};