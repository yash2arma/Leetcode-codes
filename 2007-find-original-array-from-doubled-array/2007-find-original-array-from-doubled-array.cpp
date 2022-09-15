class Solution 
{
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        if(changed.size()%2!=0) return {};
        unordered_map<int, int> mp;
        
        sort(changed.begin(), changed.end());
        vector<int> ans;
        
        for(int i=changed.size()-1; i>=0; i--)
        {
            if(mp.find(2*changed[i]) != mp.end())
            {
                ans.push_back(changed[i]);
                if(--mp[2*changed[i]] == 0) mp.erase(2*changed[i]);
                
            }
            else
            {
                mp[changed[i]]++;
            }     
        }
        if(!mp.empty()) return {};
        return ans;
    }
};