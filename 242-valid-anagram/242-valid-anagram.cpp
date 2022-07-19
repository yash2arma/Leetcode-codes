class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size()) return false;
        
        map<char, int> mp;
        
        for(int i=0; i<t.size(); i++)
        {
            mp[t[i]]++;
            mp[s[i]]--;
        }
        
        for(auto it:mp)
        {
            if(it.second) return false;
        }
        return true;
        
    }
};