class Solution 
{
public:
    
    //1. Memoization
    /*
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
    */
    
    //2. Tabulation
    bool subsetSumToK(int n, int tar, vector<int>& nums)
    {
        vector<vector<bool>> dp(n, vector<bool> (tar+1, 0));
        
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(nums[0] <= tar) dp[0][nums[0]] = true;
        
        for(int i=1; i<n; i++)
        {
            for(int k=0; k<=tar; k++)
            {
                bool not_take = dp[i-1][k];
                
                bool take=false;
                if(nums[i] <= k)
                    take = dp[i-1][k-nums[i]];
                
                dp[i][k] = take | not_take;
            }
        }
        
        return dp[n-1][tar];
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