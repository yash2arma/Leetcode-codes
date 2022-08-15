class Solution 
{
public:
    vector<int> diStringMatch(string s) 
    {
        int f=0, l=s.size();
        vector<int> ans;
        
        for(int i=0; i<=s.size(); i++)
            ans.push_back((i==s.size() || s[i]=='I') ? f++ : l--);

        return ans;
    }
};