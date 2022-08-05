class Solution 
{
public:
    //1. Memoization: 
    /*
    int help(int idx, vector<int>& nums, int tar, vector<int>& dp)
    {
        if(tar<0 || idx>=nums.size()) return 0;
        if(tar==0) return 1;
        
        if(dp[tar]!=-1) return dp[tar];
        
        int count=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= tar)
                count += help(i, nums, tar-nums[i], dp);
        }
        return dp[tar] = count;
        
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        int count = 0;
        vector<int> dp(target+1, -1);
        for(int i=0; i<nums.size(); i++)
        {
            count += help(i, nums, target-nums[i], dp);
        }
        
        return count;        
    }
    */
    
    //2. Tabulation

    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        sort (nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) 
        {
            for (auto it : nums) 
            {
                if (i < it) break;
                dp[i] += dp[i - it];
            }
        }
        return dp.back();
    }
    
};