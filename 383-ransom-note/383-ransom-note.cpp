class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int> mp(26, 0);
        
        for(auto it:magazine)
        {
            mp[it - 'a']++;
        }
        
        for(auto it:ransomNote)
        {
            mp[it-'a']--;
            if(mp[it-'a'] < 0) return false;
        }
        return true;
    }
    
};