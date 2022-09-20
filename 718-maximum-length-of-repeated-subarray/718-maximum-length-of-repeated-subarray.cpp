class Solution 
{
public:
    /*int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int maxi=0;
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        return maxi;
    }
    */
    
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        int maxi=0;
        int n=nums1.size(), m=nums2.size();
        if(n<m)
        {
            swap(nums1, nums2);
            swap(n, m);
        }
        cout<<n<<" "<<m;
        vector<int> pre(m+1), cur(m+1);
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    cur[j] = pre[j-1] + 1;
                
                else
                    cur[j] = 0;
                
                maxi = max(maxi, cur[j]);
                    
            }
            pre = cur;
        }
        return maxi;
    }
};