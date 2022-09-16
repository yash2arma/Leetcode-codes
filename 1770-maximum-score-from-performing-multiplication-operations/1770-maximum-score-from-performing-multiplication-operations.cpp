class Solution 
{
public:
    int help(int i, int n, int j, vector<int>& nums, vector<int>& multi, vector<vector<int>> &dp)
    {
        if(j==multi.size()) return 0;
        
        if(dp[i][j] != INT_MIN) return dp[i][j];
        
        int l_sum=0, h_sum=0;
        
        l_sum = nums[i]*multi[j] + help(i+1, n, j+1, nums, multi, dp);
        h_sum = nums[(n-1) - (j-i)]*multi[j] + help(i, n, j+1, nums, multi, dp);
        
        return dp[i][j] = max(l_sum, h_sum);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multi) 
    {
        int n=nums.size();
        int m=multi.size();
        vector<vector<int>> dp(m, vector<int> (m, INT_MIN));
        return help(0, n, 0, nums, multi, dp);
    }
};