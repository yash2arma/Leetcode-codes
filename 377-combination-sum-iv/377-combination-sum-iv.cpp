class Solution 
{
public:
    
    int help(int idx, vector<int>& nums, int tar, vector<vector<int>>& dp)
    {
        if(tar<0 || idx>=nums.size()) return 0;
        if(tar==0) return 1;
        
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= tar)
                count += help(i, nums, tar-nums[i], dp);
        }
        return dp[idx][tar] = count;
        
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        int count = 0;
        vector<vector<int>> dp(nums.size(), vector<int> (target, -1));
        for(int i=0; i<nums.size(); i++)
        {
            count += help(i, nums, target-nums[i], dp);
        }
        return count;        
    }
    
};