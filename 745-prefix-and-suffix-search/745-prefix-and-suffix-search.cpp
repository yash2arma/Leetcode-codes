class WordFilter {
public:
    unordered_map<string, int> mp;
    
    WordFilter(vector<string>& words) 
    {
        int n = words.size();
        
        for(int i=0; i<n; i++)
        {
            string word = words[i];
            int wordsize = word.size();
            for(int j=1; j<=wordsize; j++)
            {
                string p = word.substr(0,j);
                for(int k=0; k<wordsize; k++)
                {
                    string s = word.substr(k, wordsize);
                    mp[p +"|"+ s] = i+1;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
        string s = prefix + "|" + suffix;
        return mp[s]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */