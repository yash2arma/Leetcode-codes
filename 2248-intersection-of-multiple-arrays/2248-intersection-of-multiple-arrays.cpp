class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        vector<int> ans;
        map<int, int> mp1, mp2;
        
        for(auto it:nums[0])
            mp1[it]++;
        
        for(int i=1; i<nums.size(); i++)
        {
            for(auto it:nums[i])
                mp2[it]++;
            
            for(auto it: mp1)
            {
                mp1[it.first] = min(it.second , mp2[it.first]);
                mp2[it.first] = 0;
            }
        }
        
        for(auto it:mp1)
        {
            while(it.second > 0)
            {
                ans.push_back(it.first);
                it.second--;
            }
        }
        return ans;
    }
};