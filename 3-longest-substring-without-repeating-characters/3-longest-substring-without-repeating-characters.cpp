class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.empty()) return 0;
        unordered_map<char, int> mp;
        int f=0, e=0;
        int n=s.length(), cnt=0, maxi=0;
        
        while(e<n)
        {
            if(mp.find(s[e]) == mp.end())
            {
                mp[s[e]] = e;
                cout<<s[e]<<" "<<e<<endl;
                cnt = e-f+1;
                maxi = max(maxi, cnt); 
                e++;
            }
            
            else
            {
                while(f<mp[s[e]]) mp.erase(s[f++]);
                f = mp[s[e]]+1;
                mp[s[e]] = e;
                cout<<s[e]<<" "<<e<<endl;
                cnt = e-f+1;
                maxi = max(maxi, cnt); 
                e++;
            }
        }
        return maxi;
        
    }
};