class Solution 
{
public:
    string makeGood(string s) 
    {
        stack<char> st;
        st.push(s[0]);
        
        int i=1, n=s.size();
        char c;
        while(i<n)
        {
            if(!st.empty() && (st.top()-s[i] == 32 || s[i]-st.top() == 32))
            {
                st.pop();
            }
                 
            
            else
            {
                cout<<s[i]<<" ";
                st.push(s[i]);
            }
            i++;
                
        }
        
        string res="";
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};