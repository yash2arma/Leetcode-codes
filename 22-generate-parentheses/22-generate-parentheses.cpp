class Solution 
{
public:
    
    void help(int open, int close, string par, vector<string> &res)
    {
        if(open==0 && close==0)
        {
            res.push_back(par);
            return;
        }
        
        if(open!=0)
        {
            par += '(';
            help(open-1, close, par, res);
            par.pop_back();
        }
        
        if(close > open)
        {
            par += ')';
            help(open, close-1, par, res);
        }
        
        
        
    }
    
    vector<string> generateParenthesis(int n) 
    {
        int open=n, close=n;
        string par="";
        vector<string> res;
        help(open, close, par, res);
        return res;       
    }
};