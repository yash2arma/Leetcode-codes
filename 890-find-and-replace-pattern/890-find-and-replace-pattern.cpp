class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        if(pattern.size()==1) return words;
        unordered_map<char, char> mp_p2w;
        unordered_map<char, char> mp_w2p;
        
        vector<string> res;
        
        for(auto word:words)
        {
            mp_p2w[pattern[0]] = word[0];
            mp_w2p[word[0]] = pattern[0];
            int i;
            for(i=1; i<word.size(); i++)
            {
                if(word[i]==word[i-1] && pattern[i]!=pattern[i-1]) break;
                if(word[i]!=word[i-1] && pattern[i]==pattern[i-1]) break;
                
                if(mp_p2w.find(pattern[i]) != mp_p2w.end())
                {
                    if(mp_p2w[pattern[i]]!=word[i])
                        break;
                }   
                
                if(mp_w2p.find(word[i]) != mp_w2p.end())
                {
                    if(mp_w2p[word[i]]!=pattern[i])
                        break;
                } 
                mp_p2w[pattern[i]] = word[i]; 
                mp_w2p[word[i]] = pattern[i];
            }
            if(i==word.size())
                res.push_back(word);
            mp_p2w.clear();
            mp_w2p.clear();
        }
        return res;
    }
};