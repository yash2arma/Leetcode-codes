class Solution {
public:
    string reverseWords(string s) 
    {
        string res = "";
        string temp = "";
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ')
            {
                res = res + temp + " ";
                temp = "";
            }
            else
                temp = s[i] + temp;
        }
        if(temp!="")
            res = res + temp;
        return res;
        
    }
};