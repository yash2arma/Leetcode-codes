class Solution 
{
public:
    /*string smallestNumber(string pattern) 
    {
        string res, st;
        
        for(int i=0; i<=pattern.size(); i++)
        {
            st.push_back('1'+i);
            if(i==pattern.size() || pattern[i]=='I')
            {
                while(!st.empty())
                {
                    res.push_back(st.back());
                    st.pop_back();
                }
            }
        }
        return res; 
    }
    */
    
    string smallestNumber(string pattern) 
    {
        string res; 
        stack<char> st;
        
        for(int i=0; i<=pattern.size(); i++)
        {
            st.push('1'+i);
            if(i==pattern.size() || pattern[i]=='I')
            {
                while(!st.empty())
                {
                    res.push_back(st.top());
                    st.pop();
                }
            }
        }
        return res; 
    }
};