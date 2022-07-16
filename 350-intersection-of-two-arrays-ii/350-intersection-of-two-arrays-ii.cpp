class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(auto it:nums1)
        {
            mp[it]++;
        }
        
        for(auto it:nums2)
        {
            if(mp.find(it) != mp.end())
            {
                if(mp[it] > 0)
                    ans.push_back(it);
                mp[it]--;
            }
        }
        return ans;
        
    }
};