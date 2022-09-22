class Solution {
public:
    
    string reverseWords(string s) 
    {
        string res="", temp="";
        int low=0, n=s.size();
        
        while(low<n)
        {
            if(s[low]!=' ')
            {
                temp = s[low] + temp;
            }
            else if(s[low]==' ')
            {
                res += temp + " ";
                temp="";
            }
            low++;
        }
        res += temp;
        return res;
        
    }
    /*string reverseWords(string s) 
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
    */
    
    /*
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
    */
};