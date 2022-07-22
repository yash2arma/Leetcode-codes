class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        
        for(auto it:s)
        {
            //if string contains open bracket then put it into the stack
            if(it=='(' || it=='[' || it=='{')
            {
                st.push(it);
            }
            
            else
            {
                //base condition
                if(st.empty()) return false;
                
                //take top bracket and check whether it is just opposite of current bracket
                char c=st.top();
                st.pop();
                if((c=='[' && it==']') || (c=='{' && it=='}') || (c=='(' && it==')'))
                    continue;
                
                return false;
            }
        }
        //if stack empty it means all pairs of brackets are their.
        return st.empty();
    }
};