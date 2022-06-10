class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty()) return 0;
        unordered_map<char, int> mp;
        int f=0, e=0;
        int n=s.length(), maxi=0;
        
        while(e<n)
        {
            if(mp.find(s[e]) != mp.end())
            {
                while(f<mp[s[e]]) mp.erase(s[f++]);
                f = mp[s[e]]+1;
            }
            mp[s[e]] = e;
            maxi = max(maxi, e-f+1);
            e++;
        }
        return maxi;
        
    }
};