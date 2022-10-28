class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {   
        vector<vector<string>> res;
        
        unordered_map<string, vector<string>> mp;
        
        string temp;
        for(auto s:strs)
        {
            temp = s;
            sort(begin(temp), end(temp));
            mp[temp].push_back(s);
        }
        
        for(auto s:mp)
        {
            res.push_back(s.second);
        }
        
       
        
        return res;
    }
};