class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.size()!=t.size()) return false;
        
        map<char, int> mp;
        
        for(auto it:t)
            mp[it]++;
        
        for(auto it:s)
        {
            mp[it]--;
            if(mp.find(it)==mp.end() || mp[it]<0) return false;
        }
        return true;
        
    }
};