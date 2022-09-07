class Solution 
{
public:
    
    bool help(int i, int tar, vector<int> &nums, int &n, vector<vector<int>> &dp)
    {
        if(i==n-1) return (tar==nums[i]);
        if(tar==0) return true;
        
        if(dp[i][tar] != -1) return dp[i][tar];
        
        bool not_take = help(i+1, tar, nums, n, dp);
        
        bool take=false;
        if(nums[i] <= tar)
            take = help(i+1, tar-nums[i], nums, n, dp);
        
        return dp[i][tar] = take | not_take;
    }
    
    bool subsetSumToK(int n, int tar, vector<int>& nums)
    {
        vector<vector<int>> dp(n, vector<int> (tar+1, -1));
        return help(0, tar, nums, n, dp);
    }
    
    bool canPartition(vector<int>& nums) 
    {
        int n=nums.size();
        int sum=0;
        
        for(auto it:nums)
            sum += it;
        
        if(sum%2) return false;
        int tar = sum/2;
        return subsetSumToK(n, tar, nums);
    }
};