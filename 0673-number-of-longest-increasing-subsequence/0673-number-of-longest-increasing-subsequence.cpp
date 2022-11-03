class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi=1;
        for(int i=1; i<n; i++)
        {
            for(int pre=0; pre<i; pre++)
            {
                if(arr[i]>arr[pre] && 1+dp[pre] > dp[i])
                {
                    dp[i] = 1+dp[pre];
                    cnt[i] = cnt[pre];
                }
                else if(arr[i]>arr[pre] && 1+dp[pre]==dp[i])
                {
                    cnt[i] += cnt[pre];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int noLIS=0;
        for(int i=0; i<n; i++)
        {
            if(dp[i]==maxi)
                noLIS += cnt[i];
        }
        return noLIS;

        }
};