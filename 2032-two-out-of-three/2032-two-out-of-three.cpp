class Solution 
{
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) 
    {
        unordered_set<int> s1(nums1.begin(), nums1.end()), s2(nums2.begin(), nums2.end()), s3(nums3.begin(), nums3.end());
        
        unordered_map<int, int> mp;
        for(auto it:s1) mp[it]++;
        for(auto it:s2) mp[it]++;
        for(auto it:s3) mp[it]++;
        
        vector<int> ans;
        for(auto it:mp)
            if(it.second>1)
                ans.emplace_back(it.first);
        
        return ans;
    }
};