class Solution {
public:
    
    static bool larger(string s1, string s2)
    {
        return s1.length() > s2.length();
    }
    int minimumLengthEncoding(vector<string>& words) 
    {
        unordered_map<string, int> mp;
        int ans = 0;
        
        sort(words.begin(), words.end(), larger);
        
        
        for(auto word:words)
            mp[word]++;
        
        for(auto word:words)
        {
            int wordsize = word.size();
            if(mp[word]>0)
                ans += wordsize+1;
            
            for(int j=wordsize-1; j>=0; j--)
            {
                string s = word.substr(j, wordsize-j);
                mp[s] = 0;
            }
        }
        
        return ans;
    }
};