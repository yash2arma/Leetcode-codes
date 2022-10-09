class Solution 
{
public:
    
    string robotWithString(string s) 
    {
        vector<int> freq(26);
        
        for(auto it:s)
            freq[it-'a']++;
        
        int low=0;
        string t="", p="";
        
        for(auto it:s)
        {
            t += it;
            freq[it-'a']--;
            
            while(low < 26 && freq[low]==0)
                low++;
            
            while(!t.empty() && t.back()-'a' <= low)
            {
                p.push_back(t.back());
                t.pop_back();
            }
        }
        return p;
    }
};