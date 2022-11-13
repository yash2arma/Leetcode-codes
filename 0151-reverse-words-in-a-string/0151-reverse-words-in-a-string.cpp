class Solution {
public:
    string reverseWords(string str) 
    {
        stack<string> st;
        string s="";
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]==' ')
            {
                if(s!="")
                {
                    st.push(s);
                    s="";
                }
            }
            else
                s += str[i];
        }
        if(s!="")
            st.push(s);

        string ans="";
        while(st.size()!=1)
        {
            ans += st.top() + ' ';
            st.pop();
        }
        ans += st.top();

        return ans;
        }
};