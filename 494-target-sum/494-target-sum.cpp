class Solution 
{
public:
    int findways(int i, vector<int>&arr, int tar, vector<vector<int>> &dp)
    {
        if(i==0)
        {
            if(tar==0 && arr[0]==0) return 2;
            if(tar==0 || tar==arr[0]) return 1;
            return 0;
        }    

        if(dp[i][tar]!=-1) return dp[i][tar];

        int not_pick=0, pick=0;
        not_pick = findways(i-1, arr, tar, dp);
        if(arr[i] <= tar)
            pick = findways(i-1, arr, tar-arr[i], dp);

        return dp[i][tar] = pick+not_pick;
    }
    
    int countPartitions(int n, int tar, vector<int>& arr)
    {
        int sum = 0;
        for(auto it:arr) sum += it;

        if((sum - tar)<0 || (sum - tar)%2) return 0;
        int k=(sum-tar)/2;
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        return findways(n-1, arr, k, dp);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        return countPartitions(nums.size(), target, nums);
    }
	  
};