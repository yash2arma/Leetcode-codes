class Solution 
{
public:
    
    bool valid(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i==nums.size()) return true;
        if(i>nums.size()) return false;
        
        if(dp[i]!=-1) return false;
        if(i+1<nums.size() && nums[i]==nums[i+1])
        {
            if(valid(i+2, nums, dp)) return true;
            
            if(i+2<nums.size() && nums[i]==nums[i+2])
                if(valid(i+3, nums, dp)) return true;
        }
        
        if(i+2<nums.size() && nums[i]+1==nums[i+1] && nums[i+1]+1==nums[i+2])
            if(valid(i+3, nums, dp)) return true;
        
        return dp[i] = false;
    }
    
    bool validPartition(vector<int>& nums) 
    {
        if(nums.size()==2) return nums[0]==nums[1];
        vector<int> dp(nums.size(), -1);
        return valid(0, nums, dp);
    }
};
