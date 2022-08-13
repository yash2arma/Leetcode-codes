class Solution 
{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> res;
        int n=words.size();
        int m=words[0].size(); // each word has the same length;
        int t = m*n;
        
        if(s.size() < t) return res;
        
        unordered_map<string, int> freq;
            
        for(auto it:words)
            freq[it]++;
        
        for(int i=0; i<=s.size()-t; i++)
        {
            unordered_map<string, int> mp = freq;
            
            int j;
            for(j=0; j<s.size(); j++)
            {
                string temp = s.substr(i+j*m, m);
                
                if(mp[temp]==0)
                    break;
                else
                    mp[temp]--;
                
                /*if(mp.count(temp)==0) //it checks whether temp is present or not
                    break;
                else
                {
                    if(mp[temp]!=0) mp[temp]--;
                    else break;
                }
                */
        
            }
            if(j==n)
                res.push_back(i);
            
        }
        return res;
        
    }
};