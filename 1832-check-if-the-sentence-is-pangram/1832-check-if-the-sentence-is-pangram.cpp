class Solution 
{
public:
    bool checkIfPangram(string sentence) 
    {
        vector<int> vis(26, 0);
        
        for(auto c:sentence)
            vis[c-'a']++;
        
        for(int i=0; i<26; i++)
            if(vis[i]==0) return false;
        
        return true;           
    }
};