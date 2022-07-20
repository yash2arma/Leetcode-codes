class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        int count=words.size();
        vector<vector<int>> charMap(26);
        
        for(int i=0; i<s.size(); i++)
            charMap[s[i]-'a'].push_back(i);
            
        for(auto& word : words)
        {
            int last = -1;
            
            for(char c: word)
            {
                auto& charidx = charMap[c-'a'];
                auto it = upper_bound(charidx.begin(), charidx.end(), last);
                if(it==charidx.end()) 
                {
                    count--; break;
                }
                else last = *it;
            }
        }
        return count;
        
    }
};