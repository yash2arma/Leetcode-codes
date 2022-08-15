class Solution 
{
public:
    vector<int> diStringMatch(string s) 
    {
        int f=0, l=s.size();
        vector<int> ans;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='I')
            {
                ans.push_back(f);
                f++;
            }
            else
            {
                ans.push_back(l);
                l--;
            }
        }
        ans.push_back(l);
        return ans;
    }
};