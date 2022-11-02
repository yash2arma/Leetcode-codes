class Solution 
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), hash(n);
        int maxi=1, lastIdx=0;
        
        for(int i=1; i<n; i++)
        {
            hash[i] = i;
            for(int pre=0; pre<i; pre++)
            {
                if(nums[i]%nums[pre]==0 && dp[i] < 1 + dp[pre])
                {
                    dp[i] = 1 + dp[pre];
                    hash[i]= pre;
                }
            }
            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastIdx = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(nums[lastIdx]);
        
        while(lastIdx != hash[lastIdx])
        {
            lastIdx = hash[lastIdx];
            temp.push_back(nums[lastIdx]);
        }
        
        reverse(temp.begin(), temp.end());
        return temp;
        
    }
};