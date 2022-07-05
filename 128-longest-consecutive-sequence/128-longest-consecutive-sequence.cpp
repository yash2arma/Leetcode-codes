class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        set<int> ds;
        for(int it:nums)
            ds.insert(it);
        
        int longest = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(!ds.count(nums[i]-1))
            {
                int cur_ele = nums[i];
                int cnt = 1;
                while(ds.count(cur_ele+1))
                {
                    cnt++;
                    cur_ele = cur_ele+1;
                }
                longest = max(longest, cnt);
            }
            
        }
        return longest;
    }
};