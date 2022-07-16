class Solution {
public:
    string reverseWords(string s) 
    {
        int low=0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ')
            {
                reverse(s.begin()+low, s.begin()+i);
                low = i+1;
            }
            
        }
        reverse(s.begin()+low, s.end());
        return s;
        
    }
};