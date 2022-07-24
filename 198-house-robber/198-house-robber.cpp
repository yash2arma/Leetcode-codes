class Solution {
public:
    
    /*
    int rec(vector<int> &nums, int idx, vector<int> &dp)
    {
        if(idx>=nums.size()) return 0;
        
        if(dp[idx]!=-1) dp[idx];
        
        return dp[idx] = max(rec(nums, idx+1, dp), nums[idx]+rec(nums, idx+2, dp));
    }
    
    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+1, -1);
        return rec(nums, 0, dp);
        
    }
    */
    
    int rob(vector<int>& nums)
    {
        if(nums.size()==1) return nums[0];
        
        vector<int> dp(nums.size());
        
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        
        for(int i=2; i<nums.size(); i++)
        {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[nums.size()-1];
    }
};