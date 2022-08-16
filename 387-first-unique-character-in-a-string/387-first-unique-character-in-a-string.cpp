class Solution {
public:
    /*int firstUniqChar(string s) 
    {
        unordered_map<char, int> mp;
        
        for(auto it:s)
            mp[it]++;
        
        for(int i=0; i<s.size(); i++)
        {
            if(mp[s[i]] < 2)
                return i;
        }
        return -1;
        
    }*/
    
    int firstUniqChar(string s) 
    {
        unordered_map<char, pair<int, int>> mp; //{letter, {count, index}}
        
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]].first++;
            mp[s[i]].second = i;
        }
        
        
        int idx = s.size();
        for(auto it:mp)
        {
            if(it.second.first==1)
                idx = min(idx, it.second.second);
        }
        return idx==s.size()?-1:idx;
        
    }
};